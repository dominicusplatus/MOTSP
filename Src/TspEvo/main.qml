import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import com.tspevo.data 1.0

ApplicationWindow {

    visible: true
    width:  1024
    height:  768

    title: "ATH MOTSP"



    Rectangle{
        width:  1024 //parent.width
        height : 768 //parent.height

        TspSolverMainView {
            width:  parent.width
            height:   parent.height

        }
    }

}
