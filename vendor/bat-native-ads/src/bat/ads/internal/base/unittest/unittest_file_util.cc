/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/base/unittest/unittest_file_util.h"

#include "base/base_paths.h"
#include "base/files/file_util.h"
#include "base/path_service.h"
#include "bat/ads/internal/base/unittest/unittest_tag_parser_util.h"

namespace ads {

namespace {

base::FilePath GetRootPath() {
  base::FilePath path;
  base::PathService::Get(base::DIR_SOURCE_ROOT, &path);
  return path.AppendASCII("brave")
      .AppendASCII("vendor")
      .AppendASCII("bat-native-ads")
      .AppendASCII("data");
}

absl::optional<std::string> ReadFileToString(const base::FilePath& path) {
  std::string content;
  if (!base::ReadFileToString(path, &content)) {
    return absl::nullopt;
  }

  return content;
}

}  // namespace

base::FilePath GetTestPath() {
  return GetRootPath().AppendASCII("test");
}

absl::optional<std::string> ReadFileFromTestPathToString(
    const std::string& name) {
  const base::FilePath path = GetTestPath().AppendASCII(name);
  return ReadFileToString(path);
}

absl::optional<std::string> ReadFileFromTestPathAndParseTagsToString(
    const std::string& name) {
  absl::optional<std::string> content = ReadFileFromTestPathToString(name);
  if (!content) {
    return absl::nullopt;
  }

  ParseAndReplaceTags(&(*content));

  return *content;
}

base::FilePath GetFileResourcePath() {
  return GetTestPath().AppendASCII("resources");
}

base::FilePath GetDataResourcePath() {
  return GetRootPath().AppendASCII("resources");
}

absl::optional<std::string> ReadFileFromDataResourcePathToString(
    const std::string& name) {
  const base::FilePath path = GetDataResourcePath().AppendASCII(name);
  return ReadFileToString(path);
}

}  // namespace ads
