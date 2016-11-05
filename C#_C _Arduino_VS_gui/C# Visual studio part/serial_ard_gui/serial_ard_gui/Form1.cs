using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace serial_ard_gui
{
    public partial class Form1 : Form
    {
        private SerialPort ardport;

        public Form1()
        {
            InitializeComponent();
            serialinit();
            Display.Text = " Temperature: ";
        }

        private void button1_click(object sender, EventArgs e)
        {
            ardport.WriteLine("get");

        }

        private void serialinit()
        {
            try
            {
                ardport = new SerialPort();
                ardport.BaudRate = 9600;
                ardport.PortName = "COM4";
                ardport.Parity = Parity.None;
                ardport.StopBits = StopBits.One;
                ardport.DataBits = 8;
            
                ardport.DataReceived += new SerialDataReceivedEventHandler (DataReceivedHandler);

                ardport.Open();
            }
            catch(Exception)
            {
                MessageBox.Show("Error opening serial port");
            }
        }


        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string temdata = sp.ReadExisting();

            Display.Text = " Temperature: " + temdata;
        }
    }
}
