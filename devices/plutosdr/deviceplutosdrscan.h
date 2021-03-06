///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef DEVICES_PLUTOSDR_DEVICEPLUTOSDRSCAN_H_
#define DEVICES_PLUTOSDR_DEVICEPLUTOSDRSCAN_H_

#include <string>
#include <vector>
#include <map>

#include "export.h"

class DEVICES_API DevicePlutoSDRScan
{
public:
    struct DeviceScan
    {
        std::string m_name;
        std::string m_serial;
        std::string m_uri;
    };

    void scan();
    int getNbDevices() const { return m_scans.size(); }
    const std::string* getURIAt(unsigned int index) const;
    const std::string* getSerialAt(unsigned int index) const ;
    const std::string* getURIFromSerial(const std::string& serial) const;
    void getSerials(std::vector<std::string>& serials) const;

private:
    std::vector<DeviceScan> m_scans;
    std::map<std::string, DeviceScan*> m_serialMap;
    std::map<std::string, DeviceScan*> m_urilMap;
};



#endif /* DEVICES_PLUTOSDR_DEVICEPLUTOSDRSCAN_H_ */
