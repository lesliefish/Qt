import QtQuick 2.9
import QtQuick.Controls 2.2

Rectangle {
	width : 800;
	height : 600;
	SwipeView {
        objectName: "swipeView";
		anchors.fill : parent;
        signal signalPageChanged(int index);
        onCurrentIndexChanged: signalPageChanged(currentIndex);
		Rectangle {
			id:redRect;
			objectName:"redPage";
			color:"red";
            signal signalClicked(string objName); // redPage对象内部自定义信号

            // 内部方法设置颜色
            function setTheColor(newColor){
                color = newColor;
            }

			MouseArea {
				anchors.fill:parent;
                onClicked:redRect.signalClicked(redRect.objectName);
            }
		}
		Rectangle {
            id:greenRect;
			objectName:"greenPage";
			color:"green";
            signal signalClicked(string objName); // greenPage对象内部自定义信号
            MouseArea {
                anchors.fill:parent;
                onClicked:greenRect.signalClicked(greenRect.objectName);
            }
		}
	}
}
