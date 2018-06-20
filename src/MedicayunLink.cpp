// Copyright (c) 2015-2018 MedicayunLink
// Copyright (c) 2015-2017 The MedicayunLink Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <boost/thread.hpp>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////
//
// Start
//
bool AppInit(int argc, char* argv[])
{
    boost::thread_group threadGroup;
    CScheduler scheduler;

    bool fRet = false;

	return fRet;
}

int main(int argc, char* argv[])
{
    SetupEnvironment();

    return (AppInit(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE);
}
