import QtQuick 2.7
import QtQuick.Controls 2.2

Rectangle {
    id:root;
    width: 800;
    height: 600;
    SwipeView {
        id:swipeView;
		objectName:"swipeViewObj";
        anchors.fill: parent;
        Rectangle {
            id:page1;
            objectName: "page1Obj";
            color: "red";

            function setColor(c){
                color = c;
            }
        }
        Rectangle {
            color: "green";
        }
    }
}
