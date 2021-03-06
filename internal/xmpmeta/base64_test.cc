// Copyright 2016 The XMPMeta Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "xmpmeta/base64.h"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

namespace xmpmeta {
namespace {

TEST(Base64, EncodeAndDecodeBase64) {
  std::ostringstream data_stream;
  for (int i = 0; i <= 0xff; i++) {
    data_stream.put(static_cast<char>(i));
  }
  const string data = data_stream.str();
  const char* expected =
      "AAECAwQFBgcICQoLDA0ODxAREhMUFRYXGBkaGxwdHh8gISIjJCUm"
      "JygpKissLS4vMDEyMzQ1Njc4OTo7PD0+P0BBQkNERUZHSElKS0xNTk9QUVJTVFVWV1hZWlt"
      "cXV5fYGFiY2RlZmdoaWprbG1ub3BxcnN0dXZ3eHl6e3x9fn+AgYKDhIWGh4iJiouMjY6PkJ"
      "GSk5SVlpeYmZqbnJ2en6ChoqOkpaanqKmqq6ytrq+wsbKztLW2t7i5uru8vb6/wMHCw8TFx"
      "sfIycrLzM3Oz9DR0tPU1dbX2Nna29zd3t/g4eLj5OXm5+jp6uvs7e7v8PHy8/T19vf4+fr7"
      "/P3+/w";
  string value;
  ASSERT_TRUE(EncodeBase64(data, &value));
  ASSERT_EQ(string(expected), value);

  string decoded;
  ASSERT_TRUE(DecodeBase64(value, &decoded));
  ASSERT_EQ(data, decoded);
}

TEST(Base64, EncodeAndDecodeIntArrayBase64) {
  std::vector<int> data;
  for (int i = 0; i <= 100; i++) {
    data.push_back(i);
  }
  const string expected_values =
      "AAAAAAEAAAACAAAAAwAAAAQAAAAFAAAABgAAAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0A"
      "AAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAAAAFQAAABYAAAAXAAAAGAAAABkAAAAaAAAA"
      "GwAAABwAAAAdAAAAHgAAAB8AAAAgAAAAIQAAACIAAAAjAAAAJAAAACUAAAAmAAAAJwAAACgA"
      "AAApAAAAKgAAACsAAAAsAAAALQAAAC4AAAAvAAAAMAAAADEAAAAyAAAAMwAAADQAAAA1AAAA"
      "NgAAADcAAAA4AAAAOQAAADoAAAA7AAAAPAAAAD0AAAA+"
      "AAAAPwAAAEAAAABBAAAAQgAAAEMAAABEAAAARQAAAEYAAABHAAAASAAAAEkAAABKAAAASwAA"
      "AEwAAABNAAAATgAAAE8AAABQAAAAUQAAAFIAAABTAAAAVAAAAFUAAABWAAAAVwAAAFgAAABZ"
      "AAAAWgAAAFsAAABcAAAAXQAAAF4AAABfAAAAYAAAAGEAAABiAAAAYwAAAGQAAAA";
  string encoded;
  EXPECT_TRUE(EncodeIntArrayBase64(data, &encoded));
  EXPECT_EQ(expected_values, encoded);

  std::vector<int> decoded;
  EXPECT_TRUE(DecodeIntArrayBase64(encoded, decoded));
  EXPECT_EQ(data, decoded);
}

TEST(Base64, EncodeAndDecodeFloatArrayBase64) {
  std::vector<float> data;
  for (int i = 0; i <= 100; i++) {
    data.push_back(static_cast<float>(i));
  }
  const string expected_values =
      "AAAAAAAAgD8AAABAAABAQAAAgEAAAKBAAADAQAAA4EAAAABBAAAQQQAAIEEAADBBAABAQQAA"
      "UEEAAGBBAABwQQAAgEEAAIhBAACQQQAAmEEAAKBBAACoQQAAsEEAALhBAADAQQAAyEEAANBB"
      "AADYQQAA4EEAAOhBAADwQQAA+"
      "EEAAABCAAAEQgAACEIAAAxCAAAQQgAAFEIAABhCAAAcQgAAIEIAACRCAAAoQgAALEIAADBCA"
      "AA0QgAAOEIAADxCAABAQgAAREIAAEhCAABMQgAAUEIAAFRCAABYQgAAXEIAAGBCAABkQgAAa"
      "EIAAGxCAABwQgAAdEIAAHhCAAB8QgAAgEIAAIJCAACEQgAAhkIAAIhCAACKQgAAjEIAAI5CA"
      "ACQQgAAkkIAAJRCAACWQgAAmEIAAJpCAACcQgAAnkIAAKBCAACiQgAApEIAAKZCAACoQgAAq"
      "kIAAKxCAACuQgAAsEIAALJCAAC0QgAAtkIAALhCAAC6QgAAvEIAAL5CAADAQgAAwkIAAMRCA"
      "ADGQgAAyEI";
  string encoded;
  EXPECT_TRUE(EncodeFloatArrayBase64(data, &encoded));
  EXPECT_EQ(expected_values, encoded);

  std::vector<float> decoded;
  EXPECT_TRUE(DecodeFloatArrayBase64(encoded, decoded));
  EXPECT_EQ(data, decoded);
}

}  // namespace
}  // namespace xmpmeta
