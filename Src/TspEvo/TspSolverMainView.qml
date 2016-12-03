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

    property TspEvoSolverViewModel solverModel : TspEvoSolverViewModel{}

    Data {
        id: data
    }


    GridLayout {
        id: gridLayout
        columns: 2
        rows : 2
        width: parent.width
        height : parent.height

        Rectangle {
            width: parent.width *0.5
            height : parent.height *0.5


            GridLayout {
                id: gridLayoutGraphs
                columns: 2
                rows : 2
                width: parent.width
                height : parent.height

                Rectangle {
                    width: parent.width *0.8
                    height : parent.height *0.8
                    color: "white"

                    TspPathGraphView
                    {
                        id: graphView1
                        width: parent.width
                        height : parent.height
                        fillColor: "transparent"
                        //population: solverModel.population


                    }


                }

                Rectangle {
                    width: parent.width *0.5
                    height : parent.height *0.5
                    color: "#854268"

                }

                Rectangle {
                    width: parent.width *0.5
                    height : parent.height *0.5
                    color: "#264268"

                }

                Rectangle {
                    width: parent.width *0.5
                    height : parent.height *0.5
                    color: "#185268"

                }

            }
        }

        // We'll use one grid cell for buttons
        Rectangle {
            width: parent.width *0.5
            height : parent.height *0.5

            ChartView {
                title: "Fitness history"
                anchors.fill: parent
                antialiasing: true

                ValueAxis {
                        id: xAxisPopSize
                        min: 0
                        max: solverModel.populationSize
                    }

                ValueAxis {
                        id: yAxisFitness
                        min: solverModel.fitnessRangeStart
                        max: solverModel.fitnessRangeEnd
                    }


                LineSeries {
                    id: lineone
                    name: "Generation fitness"
                    axisX: xAxisPopSize
                    axisY: yAxisFitness

                }
                VXYModelMapper{
                    model: solverModel    //TspEvoSolverViewModel{}  //model   //TspEvoFitnessHistoryDataModel{}
                    series: lineone
                    xColumn: 0
                    yColumn: 1
                }

            }

        }

        Rectangle {
            width: parent.width *0.5
            height : parent.height *0.5
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
                    itemLabelFormat: "City (@xLabel N, @zLabel E): @yLabel"
                    ItemModelScatterDataProxy {
                        itemModel: data.sharedData
                        // Mapping model roles to scatter series item coordinates.
                        xPosRole: "Distance"
                        zPosRole: "Cost"
                        yPosRole: "Generation"
                    }
                }
            }
        }

        Rectangle {
            width: parent.width *0.5
            height : parent.height *0.5

            GridLayout {
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                columns: 2


                Label {
                    text: "Algorithm"
                }

                ComboBox {
                    currentIndex: 1
                    model: ListModel {
                        id: cbItems2
                        ListElement { text: "MOGA";  }
                        ListElement { text: "EasyEA"; }
                        ListElement { text: "IBEA"; }
                        ListElement { text: "ASEEA"; }
                        ListElement { text: "NSGA"; }
                        ListElement { text: "PLS1"; }
                        ListElement { text: "PLS2"; }
                        ListElement { text: "SEEA"; }
                        ListElement { text: "SPEA2"; }
                    }
                    width: 200
                    onCurrentIndexChanged: console.debug(cbItems.get(currentIndex).text + ", " + cbItems.get(currentIndex).color)
                }


                Label {
                    text: "Population size"
                }

                SpinBox {
                    id: spinboxPopSize
                    value : solverModel.populationSize
                    onValueChanged : {
                              solverModel.setpopulationSize(spinboxPopSize.value);
                    }
                }


                Label {
                    text: "Generations"
                }

                SpinBox {
                    id: spinboxGenerations
                    value : solverModel.generations
                    onValueChanged : {
                              solverModel.setGenerations(spinboxGenerations.value);
                    }
                }


                Label {
                    text: "Mutation probability"
                }

                SpinBox {
                    id: spinboxMutProb
                    value : solverModel.mutationProb
                    onValueChanged : {
                              solverModel.setMutationProb(spinboxMutProb.value);
                    }
                }



                NewButton {
                   // Layout.width: parent.width / 2
                    width : parent.width * 0.6
                    height : parent.height * 0.2
                    //Layout.fillHeight: true
                   // Layout.fillWidth: true
                    text: "Solve"
                    onClicked: {
                         solverModel.Solve(); // call a helper function to keep button itself simpler
                        graphView1.update();
                    }

                }


                NewButton {
                    width : parent.width * 0.6
                    height : parent.height * 0.2
                    text: "Solve Until Fit"
                    onClicked: {
                        var result = 0;
                        do{
                            solverModel.Solve();
                            graphView1.update();
                            result = solverModel.GetResult();
                        }while(result > 1400);


                    }

                }

                NewButton {
                    width : parent.width * 0.6
                    height : parent.height * 0.2
                    text: "Solve Multi objective"
                    onClicked: {
                        solverModel.SolveMOEO();

                    }

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
