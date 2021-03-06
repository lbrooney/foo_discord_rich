#pragma once

// clang-format off
// !!! Include order is important here (esp. for Win headers) !!!

#define _WIN32_WINNT _WIN32_WINNT_WIN7
#define WINVER       _WIN32_WINNT_WIN7

// Fix std min max conflicts
#define NOMINMAX
#include <WinSock2.h>
#include <Windows.h>

#include <algorithm>

// ATL/WTL
/// atlstr.h (includes atlbase.h) must be included first for CString to LPTSTR conversion to work.
#include <atlstr.h>
#include <atlapp.h>
#include <atlcrack.h>
#include <atlctrls.h>
#include <atlctrlx.h>
#include <atlddx.h>
#include <atldlgs.h>
#include <atlframe.h>
#include <atltheme.h>
#include <atltypes.h>
#include <atlwin.h>

// foobar2000 SDK
#pragma warning( push, 0 )
#include <foobar2000/SDK/foobar2000.h>
#pragma warning( pop )

// fmt
#define FMT_HEADER_ONLY
#include <fmt/format.h>

// range v3
#include <range/v3/all.hpp>

// Some macros defined by windowsx.h should be removed
#ifdef _INC_WINDOWSX
#    undef SubclassWindow
#endif

#if not __cpp_char8_t
// Dummy type
#    include <string>

using char8_t = char;
namespace std
{
using u8string = basic_string<char8_t, char_traits<char8_t>, allocator<char8_t>>;
using u8string_view = basic_string_view<char8_t>;
} // namespace std
#endif

// Unicode converters
#include <qwr/unicode.h>

// Additional PFC wrappers
#include <qwr/pfc_helpers_cfg.h>
#include <qwr/pfc_helpers_stream.h>
#include <qwr/pfc_helpers_ui.h>

#include <component_defines.h>
#include <component_guids.h>

// clang-format on
