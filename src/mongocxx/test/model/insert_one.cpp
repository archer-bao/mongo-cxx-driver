// Copyright 2016 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "helpers.hpp"

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/test_util/catch.hh>
#include <mongocxx/instance.hpp>
#include <mongocxx/model/insert_one.hpp>

using namespace bsoncxx::builder::stream;

TEST_CASE("insert_one model tests", "[insert_one][model]") {
    mongocxx::instance::current();

    auto doc = document{} << "a" << 1 << finalize;

    mongocxx::model::insert_one io(doc.view());

    SECTION("stores required arguments") {
        REQUIRE(io.document().view() == doc.view());
    }
}
