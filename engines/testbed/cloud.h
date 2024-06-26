/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef TESTBED_CLOUD_H
#define TESTBED_CLOUD_H

#include "testbed/testsuite.h"
#include "backends/cloud/storage.h"

// This file can be used as template for header files of other newer testsuites.

namespace Testbed {

namespace CloudTests {

// Helper functions for Cloud tests

bool waitForCallback();
bool waitForCallbackMore();
const char *getRemoteTestPath();
void infoCallback(const Cloud::Storage::StorageInfoResponse &response);
void directoryListedCallback(const Cloud::Storage::FileArrayResponse &response);
void directoryCreatedCallback(const Cloud::Storage::BoolResponse &response);
void fileUploadedCallback(const Cloud::Storage::UploadResponse &response);
void fileDownloadedCallback(const Cloud::Storage::BoolResponse &response);
void directoryDownloadedCallback(const Cloud::Storage::FileArrayResponse &response);
void savesSyncedCallback(const Cloud::Storage::BoolResponse &response);
void errorCallback(const Networking::ErrorResponse &response);

TestExitStatus testInfo();
TestExitStatus testDirectoryListing();
TestExitStatus testDirectoryCreating();
TestExitStatus testUploading();
TestExitStatus testDownloading();
TestExitStatus testFolderDownloading();
TestExitStatus testSavesSync();

} // End of namespace CloudTests

class CloudTestSuite : public Testsuite {
public:
	/**
	 * The constructor for the CloudTestSuite
	 * For every test to be executed one must:
	 * 1) Create a function that would invoke the test
	 * 2) Add that test to list by executing addTest()
	 *
	 * @see addTest()
	 */
	CloudTestSuite();
	~CloudTestSuite() override {}
	const char *getName() const override {
		return "Cloud";
	}

	const char *getDescription() const override {
		return "CloudMan, Storage API tests";
	}

};

} // End of namespace Testbed

#endif // TESTBED_TEMPLATE_H
