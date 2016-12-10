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

    property TspDualSolverResultSurfaceViewModel surfaceModel : TspDualSolverResultSurfaceViewModel{}


    Data {
        id: data
    }


    ListModel {
        id: sampleSurModel
        ListElement{ length: -10.0; cost: 5.0; generation: -5.0 }
        //! [0]
        ListElement{ length: -9.0; cost: 3.0; generation: -4.5 }
        ListElement{ length: -8.5; cost: 4.1; generation: -4.0 }
        ListElement{ length: -8.0; cost: 4.75; generation: -3.9 }
        ListElement{ length: -9.5; cost: 4.9; generation: -4.2 }
        ListElement{ length: -9.9; cost: 3.42; generation: -3.5 }
        ListElement{ length: -7.8; cost: 3.1; generation: -4.9 }
        ListElement{ length: -7.3; cost: 2.91; generation: -4.1 }
        ListElement{ length: -7.1 ; cost: 3.68 ; generation: -4.52 }
        ListElement{ length: -8.8 ; cost: 2.96 ; generation: -3.6 }
        ListElement{ length: -6.94 ; cost: 2.4 ; generation: -2.92 }
        ListElement{ length: -9.02 ; cost: 4.74 ; generation: -4.18 }
        ListElement{ length: -9.54 ; cost: 3.1 ; generation: -3.8 }
        ListElement{ length: -6.86 ; cost: 3.66 ; generation: -3.58 }
        ListElement{ length: -8.16 ; cost: 1.82 ; generation: -4.64 }
        ListElement{ length: -7.4 ; cost: 3.18 ; generation: -4.22 }
        ListElement{ length: -7.9 ; cost: 3.06 ; generation: -4.3 }
        ListElement{ length: -8.98 ; cost: 2.64 ; generation: -4.44 }
        ListElement{ length: -6.36 ; cost: 3.96 ; generation: -4.38 }
        ListElement{ length: -7.18 ; cost: 3.32 ; generation: -4.04 }
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
            ValueAxis3D {
                    id: xAxisCost_3d
                    min: solverModel.fitnessRangeStart
                    max: solverModel.fitnessRangeEnd
                    segmentCount: 10
                    subSegmentCount: 2
                }

            ValueAxis3D {
                    id: yAxisCost_3d
                    min: solverModel.costsRangeStart
                    max: solverModel.costsRangeEnd
                    segmentCount: 10
                    subSegmentCount: 2
                }

            ValueAxis3D {
                    id: zAxisCost_3d
                    min: 0.0
                    max: solverModel.generations
                    segmentCount: 10
                    subSegmentCount: 2
                }

            Scatter3D {
                id: scatterGraph

                anchors.fill: parent
                anchors.margins: parent.border.width

                theme: Theme3D {
                    type: Theme3D.ThemeDigia
                    font.pointSize: 60
                }

                axisX: xAxisCost_3d
                axisY: yAxisCost_3d
                axisZ: zAxisCost_3d



                width: surfaceView.width
                height: surfaceView.height


                Scatter3DSeries {

                    itemLabelFormat: "Sciezka (@xLabel Dlugosc, @zLabel Koszt): @yLabel"
                    itemSize: 0.1
                    mesh: Abstract3DSeries.MeshCube

                    ItemModelSurfaceDataProxy {
                        itemModel: sampleSurModel   //surfaceModel //   //surfaceModel
                        xPosRole: "cost"
                        yPosRole: "length"
                        zPosRole: "generation"

                        //rowRole: "cost"
                       // columnRole: "length"
                       // : "generation"

                    }
                }
            }

             */



            Item {
                id: dataView
                anchors.bottom: parent.bottom
                //! [9]
                width: parent.width
                height: parent.height
                //! [8]

                //! [2]
                Scatter3D {
                    id: scatterGraph
                    width: dataView.width
                    height: dataView.height
                    //! [2]
                    //! [3]
                    theme: Theme3D {
                        type: Theme3D.ThemeDigia
                        font.pointSize: 40
                    }

                    shadowQuality: AbstractGraph3D.ShadowQualitySoftLow
                    //! [3]
                    //! [6]
                    axisX.segmentCount: 3
                    axisX.subSegmentCount: 2
                    axisX.labelFormat: "%.2f"
                    axisZ.segmentCount: 2
                    axisZ.subSegmentCount: 2
                    axisZ.labelFormat: "%.2f"
                    axisY.segmentCount: 2
                    axisY.subSegmentCount: 2
                    axisY.labelFormat: "%.2f"
                    //! [6]
                    //! [5]
                    Scatter3DSeries {
                        id: scatterSeries
                         mesh: Abstract3DSeries.MeshCube
                        itemLabelFormat: "Series 1: X:@xLabel Y:@yLabel Z:@zLabel"

                        ItemModelScatterDataProxy {
                            itemModel:  surfaceModel    //dataModel
                            xPosRole: "cost"
                            yPosRole: "length"
                            zPosRole: "generation"
                        }
                        //! [11]
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

                        surfaceModel.updateData();
                       // TspDualSolverResultSurfaceViewModel.endResetModel();
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
