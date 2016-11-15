import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import QtQuick.Controls 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
//import com.tspevo.data 1.0

Rectangle
{
    width: parent.width
    height : parent.height

  //   property variant model:  TspEvoSolverViewModel {}

    ColumnLayout
    {
        width: parent.width
        height : parent.height

        Rectangle{
            width: parent.width
            height : parent.height * 0.5
            color: "transparent"

            RowLayout{
                width: parent.width
                height : parent.height

                Rectangle{
                    width: parent.width *0.5
                    height : parent.height
                       color: "red"
                }
                Rectangle{
                    width: parent.width *0.5
                    height : parent.height
                     color: "green"
                }
            }
        }

        Rectangle{
            width: parent.width
            height : parent.height *0.5
            color: "transparent"

            RowLayout{
                width: parent.width
                height : parent.height

                Rectangle{
                    width: parent.width *0.5
                    height : parent.height
                     color: "blue"
                }
                Rectangle{
                    width: parent.width *0.5
                    height : parent.height
                     color: "transparent"
                }
            }

        }

    }


}

