import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import QtQuick.Controls 2.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtDataVisualization 1.0
import QtCharts 2.1


import com.tspevo.data 1.0




Rectangle {
    id: mainView
    width: 800
    height: 600

    property var model : TspEvoSolverViewModel{}

    Data {
        id: data
    }

    //! [0]
    GridLayout {
        id: gridLayout
        columns: 2
        Layout.fillHeight: true
        Layout.fillWidth: true
        anchors.top: mainView.top
        anchors.bottom: mainView.bottom
        anchors.left: mainView.left
        anchors.right: mainView.right

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            border.color: surfaceGraph.theme.gridLineColor
            border.width: 2

            Surface3D {
                id: surfaceGraph
                anchors.fill: parent
                anchors.margins: parent.border.width
                theme: Theme3D {
                    type: Theme3D.ThemePrimaryColors
                    font.pointSize: 60
                }
                scene.activeCamera.cameraPreset: Camera3D.CameraPresetIsometricLeftHigh

                Surface3DSeries {
                    itemLabelFormat: "Pop density at (@xLabel N, @zLabel E): @yLabel"
                    ItemModelSurfaceDataProxy {
                        itemModel: data.sharedData
                        // The surface data points are not neatly lined up in rows and columns,
                        // so we define explicit row and column roles.
                        rowRole: "row"
                        columnRole: "col"
                        xPosRole: "latitude"
                        zPosRole: "longitude"
                        yPosRole: "pop_density"
                    }
                }
            }
        }

        // We'll use one grid cell for buttons
        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            ChartView {
                title: "Line"
                anchors.fill: parent
                antialiasing: true

                LineSeries {
                    name: "LineSeries"
                    XYPoint { x: 0; y: 0 }
                    XYPoint { x: 1.1; y: 2.1 }
                    XYPoint { x: 1.9; y: 3.3 }
                    XYPoint { x: 2.1; y: 2.1 }
                    XYPoint { x: 2.9; y: 4.9 }
                    XYPoint { x: 3.4; y: 3.0 }
                    XYPoint { x: 4.1; y: 3.3 }
                }
            }

        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            border.color: scatterGraph.theme.gridLineColor
            border.width: 2

            Scatter3D {
                id: scatterGraph
                anchors.fill: parent
                anchors.margins: parent.border.width
                theme: Theme3D {
                    type: Theme3D.ThemeDigia
                    font.pointSize: 60
                }
                scene.activeCamera.cameraPreset: Camera3D.CameraPresetIsometricLeftHigh

                Scatter3DSeries {
                    itemLabelFormat: "Pop density at (@xLabel N, @zLabel E): @yLabel"
                    ItemModelScatterDataProxy {
                        itemModel: data.sharedData
                        // Mapping model roles to scatter series item coordinates.
                        xPosRole: "latitude"
                        zPosRole: "longitude"
                        yPosRole: "pop_density"
                    }
                }
            }
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            GridLayout {
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                columns: 2

                NewButton {
                    Layout.minimumWidth: parent.width / 2
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    text: "Clear Selections"
                    onClicked: clearSelections() // call a helper function to keep button itself simpler
                }

                NewButton {
                    Layout.minimumWidth: parent.width / 2
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    text: "Quit"
                    onClicked: Qt.quit(0);
                }

                NewButton {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    text: "Reset Cameras"
                    onClicked: resetCameras() // call a helper function to keep button itself simpler
                }

                NewButton {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    text: "Toggle Mesh Styles"
                    onClicked: toggleMeshStyle() // call a helper function to keep button itself simpler
                }
            }

        }
    }
    //! [0]

    function clearSelections() {
        barGraph.clearSelection()
        scatterGraph.clearSelection()
        surfaceGraph.clearSelection()
    }

    function resetCameras() {
        surfaceGraph.scene.activeCamera.cameraPreset = Camera3D.CameraPresetIsometricLeftHigh
        scatterGraph.scene.activeCamera.cameraPreset = Camera3D.CameraPresetIsometricLeftHigh
        barGraph.scene.activeCamera.cameraPreset = Camera3D.CameraPresetIsometricLeftHigh
        surfaceGraph.scene.activeCamera.zoomLevel = 100.0
        scatterGraph.scene.activeCamera.zoomLevel = 100.0
        barGraph.scene.activeCamera.zoomLevel = 100.0
    }

    function toggleMeshStyle() {
        if (barGraph.seriesList[0].meshSmooth === true) {
            barGraph.seriesList[0].meshSmooth = false
            if (surfaceGraph.seriesList[0].flatShadingSupported)
                surfaceGraph.seriesList[0].flatShadingEnabled = true
            scatterGraph.seriesList[0].meshSmooth = false
        } else {
            barGraph.seriesList[0].meshSmooth = true
            surfaceGraph.seriesList[0].flatShadingEnabled = false
            scatterGraph.seriesList[0].meshSmooth = true
        }
    }
}


/*
GridLayout {
    id: mainNavGridLayout
    width: parent.width
    height : parent.height
    rows: 2
    columns: 2
    anchors.fill: parent

    property variant model:  TspEvoSolverViewModel {}

    Rectangle{
        width: parent.width *0.5
        height : parent.height*0.5
           color: "red"
    }
    Rectangle{
        width: parent.width  *0.5
        height : parent.height *0.5
         color: "green"
    }

    Rectangle{
        width: parent.width  *0.5
        height : parent.height *0.5
         color: "blue"
    }
    Rectangle{
        width: parent.width *0.5
        height : parent.height *0.5
         color: "transparent"
    }

}
*/
