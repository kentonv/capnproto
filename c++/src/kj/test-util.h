// Copyright (c) 2020-2021 Cap'n Proto Contributors
// Licensed under the MIT License:
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once

#include "io.h"

#if _WIN32 || __ANDROID__
// TODO(cleanup): Find the Windows temp directory? Seems overly difficult pre C++17.
// https://en.cppreference.com/w/cpp/filesystem/temp_directory_path
// would require refactoring the mkstemp code a bit to take into account the types
// needed to do this at runtime.
#define KJ_TEMP_FILE_TEMPLATE(tpl) tpl "-XXXXXX"
#else
#define KJ_TEMP_FILE_TEMPLATE(tpl) "/tmp/" tpl "-XXXXXX"
#endif

namespace kj {
namespace test {
AutoCloseFd mkstempAutoErased(char *tpl);
// Equivalent to mkstemp but guaranteed to have the temporary file cleaned up
// on or before close. *NIX platforms unlink the temporary file from the
// filesystem before returning. Windows will delete the file when the handle
// is closed.
}  // namespace test
}  // namespace kj
