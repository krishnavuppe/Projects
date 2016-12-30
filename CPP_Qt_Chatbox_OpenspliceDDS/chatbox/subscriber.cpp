#include "subscriber.h"

string usrnme[4];
string messg[4];

void CB_Listener::on_data_available(DataReader_ptr parentReader)THROW_ORB_EXCEPTIONS
{

    ReturnCode_t status;
    messageSeq msgList;
    SampleInfoSeq infoSeq;


    status = chatboxAdmin->take(msgList, infoSeq, LENGTH_UNLIMITED,
                                ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
    checkStatus(status, "messageDataReader::read");

    for (ULong j = 0; j < msgList.length(); j++)
    {

        if(msgList[j].uid == 1)
        {
            usrnme[0] = msgList[j].uname;

            if(usrnme[0].compare(username) == 0)
            {
                messg[0] = msgList[j].msg;
                msgid[0] = msgList[j].msgid;
            }
        }

        if(msgList[j].uid == 2)
        {
            usrnme[1] = msgList[j].uname;

            if(usrnme[1].compare(username) == 0)
            {
                messg[1] = msgList[j].msg;
                msgid[1] = msgList[j].msgid;
            }
        }

        if(msgList[j].uid == 3)
        {
            usrnme[2] = msgList[j].uname;

            if(usrnme[2].compare(username) == 0)
            {
                messg[2] = msgList[j].msg;
                msgid[2] = msgList[j].msgid;
            }
        }

        if(msgList[j].uid == 4)
        {
            usrnme[3] = msgList[j].uname;

            if(usrnme[3].compare(username) == 0)
            {
                messg[3] = msgList[j].msg;
                msgid[3] = msgList[j].msgid;
            }
        }


    }

    status = chatboxAdmin->return_loan(msgList, infoSeq);
    checkStatus(status, "messageDataReader::return_loan");
}

void CB_Listener::on_requested_deadline_missed(DataReader_ptr parentReader,
                                               const RequestedDeadlineMissedStatus &status)THROW_ORB_EXCEPTIONS
{
    printf("\n=== [CB_Listener::on_requested_deadline_missed] : triggered\n");
    printf("\n=== [CB_Listener::on_requested_deadline_missed] : stopping\n");
    closed = true;
    // unblock the waitset in Subscriber main loop
    escape->set_trigger_value(true);
}

void CB_Listener::on_requested_incompatible_qos(DataReader_ptr parentReader,
                                                const RequestedIncompatibleQosStatus &status)THROW_ORB_EXCEPTIONS
{
    printf("\n=== [CB_Listener::on_requested_incompatible_qos] : triggered\n");
}

void CB_Listener::on_sample_rejected(DataReader_ptr parentReader,
                                     const SampleRejectedStatus &status)THROW_ORB_EXCEPTIONS
{
    printf("\n=== [CB_Listener::on_sample_rejected] : triggered\n");
}

void CB_Listener::on_liveliness_changed(DataReader_ptr parentReader,
                                        const LivelinessChangedStatus &status)THROW_ORB_EXCEPTIONS
{
    printf("\n=== [CB_Listener::on_liveliness_changed] : triggered\n");
}

void CB_Listener::on_subscription_matched(DataReader_ptr parentReader,
                                          const SubscriptionMatchedStatus &status)THROW_ORB_EXCEPTIONS
{
    printf("\n=== [CB_Listener::on_subscription_matched] : triggered\n");
}

void CB_Listener::on_sample_lost(DataReader_ptr parentReader,
                                 const SampleLostStatus &status)THROW_ORB_EXCEPTIONS
{
    printf("\n=== [CB_Listener::on_sample_lost] : triggered\n");
}

CB_Subscriber::CB_Subscriber(QTextEdit *d, QTextEdit *d2, QTextEdit *d3, QTextEdit *d4)
{
    mdisp = d;
    mdisp2 = d2;
    mdisp3 = d3;
    mdisp4 = d4;

    /* Create a DomainParticipantFactory and a DomainParticipant (using Default QoS settings). */
    dpf = DomainParticipantFactory::get_instance ();
    checkHandle(dpf.in(), "DDS::DomainParticipantFactory::get_instance");
    participant = dpf->create_participant(domain, PARTICIPANT_QOS_DEFAULT, NULL, STATUS_MASK_NONE);
    checkHandle(participant.in(), "DDS::DomainParticipantFactory_Sender::create_participant");

    /* Register the required datatype for message. */
    messageTS = new messageTypeSupport();
    checkHandle(messageTS.in(), "new messageTypeSupport");
    messageTypeName = messageTS->get_type_name();
    status = messageTS->register_type(participant.in(), messageTypeName);
    checkStatus(status, "chatbox::messageTypeSupport::register_type");

    /* Set the HistoryQosPolicy to History, with a depth of 20 to keep track */
    status = participant->get_default_topic_qos(history_topic_qos);
    checkStatus(status, "DDS::DomainParticipant::get_default_topic_qos");
    history_topic_qos.history.kind = DDS::KEEP_LAST_HISTORY_QOS;
    history_topic_qos.history.depth = 20;

    /* Make the tailored QoS the new default. */
    status = participant->set_default_topic_qos(history_topic_qos);
    checkStatus(status, "DDS::DomainParticipant::set_default_topic_qos");

    /* Use the changed QoS policy when defining the message topic */
    messageTopic = participant->create_topic("chatbox_message", messageTypeName, history_topic_qos, NULL, STATUS_MASK_NONE);
    checkHandle(messageTopic.in(), "DDS::DomainParticipant::create_topic (message)");

    /* Adapt the default SubscriberQos to read from the "ChatRoom" Partition. */
    status = participant->get_default_subscriber_qos (sub_qos);
    checkStatus(status, "DDS::DomainParticipant::get_default_subscriber_qos");
    sub_qos.partition.name.length(1);
    sub_qos.partition.name[0] = partitionName;

    /* Create a Subscriber for the chatbox application. */
    chatboxSubscriber = participant->create_subscriber(sub_qos, NULL, STATUS_MASK_NONE);
    checkHandle(chatboxSubscriber.in(), "DDS::DomainParticipant::create_subscriber");

    /* Create a DataReader for the messageTopic (using the appropriate QoS). */
    parentReader = chatboxSubscriber->create_datareader(messageTopic.in(), DATAREADER_QOS_USE_TOPIC_QOS, NULL,
                                                        STATUS_MASK_NONE);
    checkHandle(parentReader.in(), "DDS::Subscriber::create_datareader");

    DataReader_var parentReader = getReader();

    CB_Listener *listn = new CB_Listener;

    listn->chatboxAdmin = messageDataReader::_narrow(parentReader.in());
    checkHandle(listn->chatboxAdmin.in(), "messageDataReader::_narrow");

    StatusMask mask = DATA_AVAILABLE_STATUS;

    listn->chatboxAdmin->set_listener(listn, mask);

    // waitset used to avoid spinning in the loop below
    WaitSet_var ws = new WaitSet();
    ws->attach_condition(listn->escape);
    ConditionSeq condSeq;

    connect(&timer, SIGNAL(timeout()),this,SLOT(update()));
    timer.start(0);

    while (!listn->closed && count < 1 )

    {
        // To avoid spinning here. We can either use a sleep or better a WaitSet.
        ws->wait(condSeq, timeout);
        listn->escape->set_trigger_value(false);
        ++count;
    }
}

CB_Subscriber::~CB_Subscriber()
{
    /* Remove the DataReader */
    status = chatboxSubscriber->delete_datareader(parentReader.in());
    checkStatus(status, "DDS::Subscriber::delete_datareader(parentReader");

    /* Remove the Subscriber. */
    status = participant->delete_subscriber(chatboxSubscriber.in());
    checkStatus(status, "DDS::DomainParticipant::delete_subscriber");

    /* Remove the Topics. */
    status = participant->delete_topic(messageTopic.in());
    checkStatus(status, "DDS::DomainParticipant::delete_topic (messageTopic)");

    /* De-allocate the type-names. */
    string_free(messageTypeName);

    /* Remove the DomainParticipant. */
    status = dpf->delete_participant(participant.in());
    checkStatus(status, "DDS::DomainParticipantFactory::delete_participant");

}

DataReader_ptr CB_Subscriber::getReader()
{
    return DataReader::_duplicate(parentReader.in());
}

void CB_Subscriber::update()
{

    if(disp==0)
    {
        mdisp->hide();
        mdisp2->hide();
        mdisp3->hide();
        mdisp4->hide();
    }

    if(msgid[0]>recvcounter[0])
    {
        recvcounter[0]++;
        mdisp->setTextColor(Qt::blue);
        mdisp->append("Akhil: " + QString::fromStdString(messg[0]) + " " + QTime::currentTime().toString());
        mdisp->setAlignment(Qt::AlignLeft);
    }

    if(msgid[1]>recvcounter[1])
    {
        recvcounter[1]++;
        mdisp2->setTextColor(Qt::blue);
        mdisp2->append("Chaitu: " + QString::fromStdString(messg[1]) + " " + QTime::currentTime().toString());
        mdisp2->setAlignment(Qt::AlignLeft);
    }

    if(msgid[2]>recvcounter[2])
    {
        recvcounter[2]++;
        mdisp3->setTextColor(Qt::blue);
        mdisp3->append("Alekya: " + QString::fromStdString(messg[2]) + " " + QTime::currentTime().toString());
        mdisp3->setAlignment(Qt::AlignLeft);
    }

    if(msgid[3]>recvcounter[3])
    {
        recvcounter[3]++;
        mdisp4->setTextColor(Qt::blue);
        mdisp4->append("Ravi: " + QString::fromStdString(messg[3]) + " " + QTime::currentTime().toString());
        mdisp4->setAlignment(Qt::AlignLeft);
    }

}
