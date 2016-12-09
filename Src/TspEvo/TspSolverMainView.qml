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
                    width: parent.width *0.5
                    height : parent.height *0.5
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
                    color: "white"

                    TspPathGraphView
                    {
                        id: graphView12
                        width: parent.width
                        height : parent.height
                        fillColor: "transparent"
                        //population: solverModel.population

                    }

                }

                Rectangle {
                    width: parent.width *0.5
                    height : parent.height *0.5
                    color: "white"

                    TspPathGraphView
                    {
                        id: graphView123
                        width: parent.width
                        height : parent.height
                        fillColor: "transparent"
                        //population: solverModel.population

                    }

                }

                Rectangle {
                    width: parent.width *0.5
                    height : parent.height *0.5
                    color: "white"

                    TspPathGraphView
                    {
                        id: graphView1234
                        width: parent.width
                        height : parent.height
                        fillColor: "transparent"
                        //population: solverModel.population

                    }

                }

            }
        }

        // We'll use one grid cell for buttons
        Rectangle {
            width: parent.width *0.5
            height : parent.height *0.5

            ChartView {
                title: "TSP generation history"
                anchors.fill: parent
                antialiasing: true

                ValueAxis {
                        id: xAxisPopSize
                        min: 0
                        max: solverModel.generations
                    }

                ValueAxis {
                        id: yAxisLength
                        min: solverModel.fitnessRangeStart
                        max: solverModel.fitnessRangeEnd
                    }
                ValueAxis {
                        id: yAxisCost
                        min: solverModel.costsRangeStart
                        max: solverModel.costsRangeEnd
                    }


                LineSeries {
                    id: lineone
                    name: "Length"
                    axisX: xAxisPopSize
                    axisY: yAxisLength

                }


                VXYModelMapper{
                    model: solverModel    //TspEvoSolverViewModel{}  //model   //TspEvoFitnessHistoryDataModel{}
                    series: lineone
                    xColumn: 0
                    yColumn: 1
                }



                LineSeries {
                    id: lineone2
                    name: "Cost"
                    axisX: xAxisPopSize
                    axisY: yAxisCost

                }
                VXYModelMapper{
                    model: solverModel    //TspEvoSolverViewModel{}  //model   //TspEvoFitnessHistoryDataModel{}
                    series: lineone2
                    xColumn: 2
                    yColumn: 3
                }

            }

        }

        Rectangle {
            width: parent.width *0.5
            height : parent.height *0.5
            border.color: scatterGraph.theme.gridLineColor
            border.width: 2

            /*
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

            */

            Item {
                 id: surfaceView
                 width: parent.width
                 height: parent.height
                 anchors.top: parent.top
                 anchors.left: parent.left

                 Data {
                     id: surfaceData
                 }

                 //! [0]
                 ColorGradient {
                     id: surfaceGradient
                     ColorGradientStop { position: 0.0; color: "darkslategray" }
                     ColorGradientStop { id: middleGradient; position: 0.25; color: "peru" }
                     ColorGradientStop { position: 1.0; color: "red" }
                 }
                 //! [0]

                 Surface3D {
                     id: surfacePlot
                     width: surfaceView.width
                     height: surfaceView.height
                     //! [7]
                     theme: Theme3D {
                         type: Theme3D.ThemeStoneMoss
                         font.family: "STCaiyun"
                         font.pointSize: 35
                         colorStyle: Theme3D.ColorStyleRangeGradient
                         baseGradients: [surfaceGradient]
                     }
                     //! [7]
                     shadowQuality: AbstractGraph3D.ShadowQualityMedium
                     selectionMode: AbstractGraph3D.SelectionSlice | AbstractGraph3D.SelectionItemAndRow
                     scene.activeCamera.cameraPreset: Camera3D.CameraPresetIsometricLeft
                     axisY.min: 0.0
                     axisY.max: 500.0
                     axisX.segmentCount: 10
                     axisX.subSegmentCount: 2
                     axisX.labelFormat: "%i"
                     axisZ.segmentCount: 10
                     axisZ.subSegmentCount: 2
                     axisZ.labelFormat: "%i"
                     axisY.segmentCount: 5
                     axisY.subSegmentCount: 2
                     axisY.labelFormat: "%i"
                     axisY.title: "Height"
                     axisX.title: "Latitude"
                     axisZ.title: "Longitude"

                     //! [5]
                     Surface3DSeries {
                         id: surfaceSeries
                         flatShadingEnabled: false
                         drawMode: Surface3DSeries.DrawSurface

                         ItemModelSurfaceDataProxy {
                             //! [5]
                             //! [6]
                             itemModel: surfaceData.model
                             rowRole: "longitude"
                             columnRole: "latitude"
                             yPosRole: "height"
                         }
                         //! [6]
                         onDrawModeChanged: checkState()
                     }
                     //! [4]
                     Surface3DSeries {
                         id: heightSeries
                         flatShadingEnabled: false
                         drawMode: Surface3DSeries.DrawSurface
                         visible: false

                         HeightMapSurfaceDataProxy {
                             heightMapFile: ":/heightmaps/image"
                             // We don't want the default data values set by heightmap proxy.
                             minZValue: 30
                             maxZValue: 60
                             minXValue: 67
                             maxXValue: 97
                         }

                         onDrawModeChanged: checkState()
                     }
                     //! [4]
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
                    textRole: "text"
                    model: ListModel {
                        id: cbItems2
                        ListElement { text: "MOGA";   param: 1; }
                        ListElement { text: "NSGA";     param: 2; }
                        ListElement { text: "NSGA-II";   param: 3; }
                        ListElement { text: "SPEA2";  param: 4; }
                        ListElement { text: "IBEA";   param: 5;}
                        ListElement { text: "SEEA";   param: 6;}
                    }
                    width: 200
                    onCurrentIndexChanged: {
                        //console.debug(cbItems.get(currentIndex).text + ", " + cbItems.get(currentIndex).color)
                        solverModel.SetMethod( cbItems2.get(currentIndex).param);
                    }

                }


                Label {
                    text: "Dataset"
                }

                ComboBox
                {
                    currentIndex: 1
                    textRole: "text"
                    model: ListModel {
                        id: cbItems266
                        ListElement { text: "ALI535";   param: 1;   }
                        ListElement { text: "ELI101";     param: 2; }
                        ListElement { text: "PR2392";   param: 3;   }
                        ListElement { text: "RL5915";  param: 4;    }
                        ListElement { text: "USA13509";   param: 5; }
                        ListElement { text: "TEST1";   param: 6;     }
                        ListElement { text: "TEST2";   param: 7;     }
                    }
                    width: 200
                    onCurrentIndexChanged: {
                        solverModel.SetDataset( cbItems266.get(currentIndex).param);
                    }

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
                    text: "Mutation probability %"
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
                        solverModel.SolveMOEO();
                      //  solverModel.GetResult();
                        graphView1.update();
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
