import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQml 2.2

Window {
    visible: true
    id: mainwindow
    width: 480
    height: 620

    Item {
        id: stat
        property var temp: ""
    }

    Rectangle{
        id: rootrect
        width: mainwindow.width
        height: mainwindow.height
        color: "#7eb1c8"

        GridLayout {
            anchors.fill: parent
            anchors.margins: 20
            rowSpacing: 20
            columnSpacing: 20
            flow:  width > height ? GridLayout.LeftToRight : GridLayout.TopToBottom

            Rectangle {
                id: displayrect
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "white"

                Text{
                    id: disp
                    anchors.top: displayrect.top
                    anchors.left: displayrect.left
                    width: displayrect.width
                    height: displayrect.height
                    wrapMode: Text.WordWrap
                    text: "Calc app developed by Krishna Vuppe"
                    font.family: "Helvetica"
                    font.pointSize: 36
                    color: "red"

                }

            }


            Rectangle {
                id: keyboardrect
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "#1e1b18"

                GridLayout{
                    anchors.fill: keyboardrect
                    anchors.margins: 2
                    rowSpacing: 2
                    columnSpacing: 2
                    flow: GridLayout.LeftToRight


                    Rectangle{
                        id:rectcol1
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: "#1e1b18"

                        GridLayout{
                            anchors.fill: rectcol1
                            anchors.margins: 2
                            rowSpacing: 2
                            columnSpacing: 2
                            flow: GridLayout.TopToBottom

                            Rectangle{
                                id: rect7
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rect7
                                    text: "7"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rect7
                                    onClicked: {
                                        stat.temp += "7"
                                        disp.text = stat.temp
                                    }

                                }
                            }

                            Rectangle{
                                id: rect4
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rect4
                                    text: "4"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rect4
                                    onClicked: {
                                        stat.temp += "4"
                                        disp.text = stat.temp
                                    }

                                }
                            }
                            Rectangle{
                                id: rect1
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rect1
                                    text: "1"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rect1
                                    onClicked: {
                                        stat.temp += "1"
                                        disp.text = stat.temp
                                    }

                                }
                            }

                            Rectangle{
                                id: rectdot
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rectdot
                                    text: "."
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rectdot
                                    onClicked: {
                                        stat.temp += "."
                                        disp.text = stat.temp
                                    }

                                }
                            }
                        }

                    }


                    Rectangle{
                        id:rectcol2
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: "#1e1b18"

                        GridLayout{
                            anchors.fill: rectcol2
                            anchors.margins: 2
                            rowSpacing: 2
                            columnSpacing: 2
                            flow: GridLayout.TopToBottom

                            Rectangle{
                                id: rect8
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rect8
                                    text: "8"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rect8
                                    onClicked: {
                                        stat.temp += "8"
                                        disp.text = stat.temp
                                    }

                                }
                            }

                            Rectangle{
                                id: rect5
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rect5
                                    text: "5"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rect5
                                    onClicked: {
                                        stat.temp += "5"
                                        disp.text = stat.temp
                                    }

                                }
                            }

                            Rectangle{
                                id: rect2
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rect2
                                    text: "2"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rect2
                                    onClicked: {
                                        stat.temp += "2"
                                        disp.text = stat.temp
                                    }

                                }

                            }

                            Rectangle{
                                id: rect0
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rect0
                                    text: "0"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rect0
                                    onClicked: {
                                        stat.temp += "0"
                                        disp.text = stat.temp
                                    }

                                }
                            }

                        }

                    }


                    Rectangle{
                        id:rectcol3
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: "#1e1b18"

                        GridLayout{
                            anchors.fill: rectcol3
                            anchors.margins: 2
                            rowSpacing: 2
                            columnSpacing: 2
                            flow: GridLayout.TopToBottom

                            Rectangle{
                                id: rect9
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rect9
                                    text: "9"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rect9
                                    onClicked: {
                                        stat.temp += "9"
                                        disp.text = stat.temp
                                    }

                                }
                            }

                            Rectangle{
                                id: rect6
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rect6
                                    text: "6"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rect6
                                    onClicked: {
                                        stat.temp += "6"
                                        disp.text = stat.temp
                                    }

                                }
                            }

                            Rectangle{
                                id: rect3
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rect3
                                    text: "3"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rect3
                                    onClicked: {
                                        stat.temp += "3"
                                        disp.text = stat.temp
                                    }

                                }
                            }

                            Rectangle{
                                id: rectequal
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rectequal
                                    text: "="
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rectequal
                                    onClicked: {
                                        disp.text = eval(disp.text)
                                        stat.temp = ""
                                    }

                                }

                            }

                        }

                    }


                    Rectangle{
                        id:rectcol4
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: "#1e1b18"

                        GridLayout{
                            anchors.fill: rectcol4
                            anchors.margins: 2
                            rowSpacing: 2
                            columnSpacing: 2
                            flow: GridLayout.TopToBottom

                            Rectangle{
                                id: rectdel
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rectdel
                                    text: "DEL"
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rectdel
                                    onClicked: {
                                        disp.text = disp.text.substring(0,disp.text.length-1)
                                        stat.temp = disp.text
                                    }

                                }
                            }

                            Rectangle{
                                id: rectdiv
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rectdiv
                                    text: " / "
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rectdiv
                                    onClicked: {
                                        stat.temp += " / "
                                        disp.text = stat.temp
                                    }

                                }
                            }

                            Rectangle{
                                id: rectmul
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rectmul
                                    text: " * "
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rectmul
                                    onClicked: {
                                        stat.temp += " * "
                                        disp.text = stat.temp
                                    }

                                }
                            }

                            Rectangle{
                                id: rectmin
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rectmin
                                    text: " - "
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rectmin
                                    onClicked: {
                                        stat.temp += " - "
                                        disp.text = stat.temp
                                    }

                                }
                            }

                            Rectangle{
                                id: rectplu
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "#c2c8c8"
                                Label {
                                    anchors.centerIn: rectplu
                                    text: " + "
                                    color: "black"
                                }

                                MouseArea{
                                    anchors.fill: rectplu
                                    onClicked: {
                                        stat.temp += " + "
                                        disp.text = stat.temp
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
