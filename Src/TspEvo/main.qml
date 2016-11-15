import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import com.tspevo.data 1.0

ApplicationWindow {

    visible: true
    width:  1024
    height:  768

    property Component internalDelegate
    property QtObject alarmSystemModel

    TspSolverMainView {
        width:  parent.width
        height:   parent.height

    }

}
