// Copyright 2017 MongoDB Inc.
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

#include <mongocxx/result/gridfs/upload.hpp>

#include <bsoncxx/builder/stream/array.hpp>

#include <mongocxx/config/private/prelude.hh>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace result {
namespace gridfs {

upload::upload(bsoncxx::types::value id)
    : _id_owned(bsoncxx::builder::stream::array{} << id << bsoncxx::builder::stream::finalize),
      _id(_id_owned.view()[0].get_value()) {}

const bsoncxx::types::value& upload::id() const {
    return _id;
}

}  // namespace gridfs
}  // namespace result
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx
