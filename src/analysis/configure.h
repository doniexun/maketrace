// Copyright 2016 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ANALYSIS_CONFIGURE_H_
#define ANALYSIS_CONFIGURE_H_

#include <memory>

#include "common.h"
#include "tracer.pb.h"
#include "tracereader.h"
#include "utils/recordfile.h"

namespace analysis {

class Configure {
 public:
  struct Options {
    // Read trace records from this file.
    QString trace_filename;

    // Write a ConfigureOutput record to this file.
    QString output_filename;
  };

  static bool Run(const Options& opts);

 private:
  Configure(const Options& opts);
  ~Configure();

  bool OpenTrace();
  void FindCreatedFiles();
  bool WriteOutput();

  const Options opts_;
  TraceReader trace_;
  pb::ConfigureOutput output_;
};

}  // namespace analysis

#endif  // ANALYSIS_CONFIGURE_H_
