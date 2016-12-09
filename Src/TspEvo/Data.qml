/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Data Visualization module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.7
import QtQuick.Controls 2.0

Item {
    property alias sharedData: dataModel

    ListModel {
        id: dataModel
        ListElement{ longitude: "0"; latitude: "0"; height: "124"; }
        ListElement{ longitude: "0"; latitude: "1"; height: "125"; }
        ListElement{ longitude: "0"; latitude: "2"; height: "124"; }
        //! [0]
        ListElement{ longitude: "0"; latitude: "3"; height: "118"; }
        ListElement{ longitude: "0"; latitude: "4"; height: "112"; }
        ListElement{ longitude: "0"; latitude: "5"; height: "111"; }
        ListElement{ longitude: "0"; latitude: "6"; height: "115"; }
        ListElement{ longitude: "0"; latitude: "7"; height: "102"; }
        ListElement{ longitude: "0"; latitude: "8"; height: "115"; }
        ListElement{ longitude: "0"; latitude: "9"; height: "126"; }
        ListElement{ longitude: "0"; latitude: "10"; height: "127"; }
        ListElement{ longitude: "0"; latitude: "11"; height: "127"; }
        ListElement{ longitude: "0"; latitude: "12"; height: "124"; }
        ListElement{ longitude: "0"; latitude: "13"; height: "120"; }
        ListElement{ longitude: "0"; latitude: "14"; height: "117"; }
        ListElement{ longitude: "0"; latitude: "15"; height: "116"; }
        ListElement{ longitude: "0"; latitude: "16"; height: "114"; }
        ListElement{ longitude: "0"; latitude: "17"; height: "112"; }
        ListElement{ longitude: "0"; latitude: "18"; height: "114"; }
        ListElement{ longitude: "0"; latitude: "19"; height: "114"; }
        ListElement{ longitude: "0"; latitude: "20"; height: "112"; }
        ListElement{ longitude: "0"; latitude: "21"; height: "112"; }
        ListElement{ longitude: "0"; latitude: "22"; height: "116"; }
        ListElement{ longitude: "0"; latitude: "23"; height: "117"; }
        ListElement{ longitude: "0"; latitude: "24"; height: "118"; }
        ListElement{ longitude: "0"; latitude: "25"; height: "119"; }
        ListElement{ longitude: "0"; latitude: "26"; height: "117"; }
        ListElement{ longitude: "0"; latitude: "27"; height: "115"; }
        ListElement{ longitude: "0"; latitude: "28"; height: "112"; }
        ListElement{ longitude: "0"; latitude: "29"; height: "109"; }
        ListElement{ longitude: "0"; latitude: "30"; height: "108"; }
        ListElement{ longitude: "0"; latitude: "31"; height: "105"; }
        ListElement{ longitude: "0"; latitude: "32"; height: "105"; }
        ListElement{ longitude: "0"; latitude: "33"; height: "104"; }
        ListElement{ longitude: "0"; latitude: "34"; height: "105"; }
        ListElement{ longitude: "0"; latitude: "35"; height: "107"; }
        ListElement{ longitude: "0"; latitude: "36"; height: "110"; }
        ListElement{ longitude: "0"; latitude: "37"; height: "114"; }
        ListElement{ longitude: "0"; latitude: "38"; height: "117"; }
        ListElement{ longitude: "0"; latitude: "39"; height: "119"; }
        ListElement{ longitude: "0"; latitude: "40"; height: "121"; }
        ListElement{ longitude: "0"; latitude: "41"; height: "123"; }
        ListElement{ longitude: "0"; latitude: "42"; height: "125"; }
        ListElement{ longitude: "0"; latitude: "43"; height: "126"; }
        ListElement{ longitude: "0"; latitude: "44"; height: "119"; }
        ListElement{ longitude: "0"; latitude: "45"; height: "115"; }
        ListElement{ longitude: "0"; latitude: "46"; height: "114"; }
        ListElement{ longitude: "0"; latitude: "47"; height: "123"; }
        ListElement{ longitude: "0"; latitude: "48"; height: "131"; }
        ListElement{ longitude: "0"; latitude: "49"; height: "130"; }
        ListElement{ longitude: "0"; latitude: "50"; height: "128"; }
        ListElement{ longitude: "0"; latitude: "51"; height: "124"; }
        ListElement{ longitude: "0"; latitude: "52"; height: "121"; }
        ListElement{ longitude: "0"; latitude: "53"; height: "120"; }
        ListElement{ longitude: "0"; latitude: "54"; height: "118"; }
        ListElement{ longitude: "0"; latitude: "55"; height: "116"; }
        ListElement{ longitude: "0"; latitude: "56"; height: "116"; }
        ListElement{ longitude: "0"; latitude: "57"; height: "115"; }
        ListElement{ longitude: "0"; latitude: "58"; height: "112"; }
        ListElement{ longitude: "0"; latitude: "59"; height: "110"; }
        ListElement{ longitude: "0"; latitude: "60"; height: "109"; }
        ListElement{ longitude: "0"; latitude: "61"; height: "107"; }
        ListElement{ longitude: "0"; latitude: "62"; height: "107"; }
        ListElement{ longitude: "0"; latitude: "63"; height: "108"; }
        ListElement{ longitude: "0"; latitude: "64"; height: "110"; }
        ListElement{ longitude: "0"; latitude: "65"; height: "113"; }
        ListElement{ longitude: "0"; latitude: "66"; height: "115"; }
        ListElement{ longitude: "0"; latitude: "67"; height: "117"; }
        ListElement{ longitude: "0"; latitude: "68"; height: "119"; }
        ListElement{ longitude: "0"; latitude: "69"; height: "121"; }
        ListElement{ longitude: "0"; latitude: "70"; height: "122"; }
        ListElement{ longitude: "0"; latitude: "71"; height: "124"; }
        ListElement{ longitude: "0"; latitude: "72"; height: "125"; }
        ListElement{ longitude: "0"; latitude: "73"; height: "125"; }
        ListElement{ longitude: "0"; latitude: "74"; height: "125"; }
        ListElement{ longitude: "0"; latitude: "75"; height: "123"; }
        ListElement{ longitude: "0"; latitude: "76"; height: "123"; }
        ListElement{ longitude: "0"; latitude: "77"; height: "122"; }
        ListElement{ longitude: "0"; latitude: "78"; height: "125"; }
        ListElement{ longitude: "0"; latitude: "79"; height: "129"; }
        ListElement{ longitude: "0"; latitude: "80"; height: "135"; }
        ListElement{ longitude: "0"; latitude: "81"; height: "138"; }
        ListElement{ longitude: "0"; latitude: "82"; height: "136"; }
        ListElement{ longitude: "0"; latitude: "83"; height: "129"; }
        ListElement{ longitude: "0"; latitude: "84"; height: "121"; }
        ListElement{ longitude: "0"; latitude: "85"; height: "116"; }
        ListElement{ longitude: "0"; latitude: "86"; height: "115"; }
        ListElement{ longitude: "0"; latitude: "87"; height: "118"; }
        ListElement{ longitude: "0"; latitude: "88"; height: "122"; }
        ListElement{ longitude: "0"; latitude: "89"; height: "127"; }
        ListElement{ longitude: "0"; latitude: "90"; height: "129"; }
        ListElement{ longitude: "0"; latitude: "91"; height: "130"; }
        ListElement{ longitude: "0"; latitude: "92"; height: "130"; }
        ListElement{ longitude: "0"; latitude: "93"; height: "128"; }
        ListElement{ longitude: "0"; latitude: "94"; height: "128"; }
        ListElement{ longitude: "0"; latitude: "95"; height: "129"; }
        ListElement{ longitude: "0"; latitude: "96"; height: "133"; }
        ListElement{ longitude: "0"; latitude: "97"; height: "138"; }
        ListElement{ longitude: "0"; latitude: "98"; height: "139"; }
        ListElement{ longitude: "0"; latitude: "99"; height: "128"; }
        ListElement{ longitude: "1"; latitude: "0"; height: "120"; }
        ListElement{ longitude: "1"; latitude: "1"; height: "120"; }
        ListElement{ longitude: "1"; latitude: "2"; height: "118"; }
        ListElement{ longitude: "1"; latitude: "3"; height: "110"; }
        ListElement{ longitude: "1"; latitude: "4"; height: "105"; }
        ListElement{ longitude: "1"; latitude: "5"; height: "110"; }
        ListElement{ longitude: "1"; latitude: "6"; height: "116"; }
        ListElement{ longitude: "1"; latitude: "7"; height: "117"; }
        ListElement{ longitude: "1"; latitude: "8"; height: "123"; }
        ListElement{ longitude: "1"; latitude: "9"; height: "128"; }
        ListElement{ longitude: "1"; latitude: "10"; height: "131"; }
        ListElement{ longitude: "1"; latitude: "11"; height: "130"; }
    }
}

