import QtQuick 1.1
import com.nokia.symbian 1.1

Page {
    id: mainPage

    Image {
        id: image1
        x: 45
        y: 75
        width: 270
        height: 110
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        z: 1
        fillMode: Image.Stretch
        sourceSize.width: 270
        sourceSize.height: 110
        source: "epitech.png"
    }

    Rectangle {
        id: rectangle1
        color: "#336eb0"
        anchors.fill: parent

        TextField {
            id: textfield1
            x: 90
            y: 260
            width: 180
            height: 50
            placeholderText: "Login"
            inputMask: ""
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
        }

        TextField {
            id: textfield2
            x: 90
            y: 325
            width: 180
            height: 50
            placeholderText: "Mot de passe"
            echoMode: 2
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
        }

        ToolButton {
            id: toolbutton1
            objectName: "buttonConnect"
            x: 108
            y: 395
            width: 145
            height: 50
            text: "Connexion"

            signal qmlSignal(string login, string password)

            onClicked: {
                toolbutton1.qmlSignal(textfield1.text, textfield2.text);
            }
            function showDialog(id) {
                console.log("id = " + id);
                if (id == 2)
                {
                dialog1.open();
                }
                else if (id == 0)
                {
                    dialog2.open();
                }
            }
        }
    }

    QueryDialog {
             id: dialog1
             // objectName: "dialogLoginError"
             titleText: "Erreur"
             acceptButtonText: "Fermer"
             message: "Vous avez rentr\351 un mauvais login ou mot de passe"
         }

    QueryDialog {
             id: dialog2
             titleText: "Connexion \351tablie"
             acceptButtonText: "OK"
             message: "Vous \353tes connect\351"
         }

}
