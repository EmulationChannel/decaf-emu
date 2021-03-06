#pragma once
#include <memory>
#include <string>
#include <vector>
#include <utility>

namespace decaf
{

struct DebuggerSettings
{
   bool enabled = true;
   bool break_on_entry = false;
   bool break_on_exit = true;
   bool gdb_stub = false;
   unsigned gdb_stub_port = 2159;
};

struct Gx2Settings
{
   bool dump_textures = false;
   bool dump_shaders = false;
   bool dump_shader_binaries_only = false;
};

struct LogSettings
{
   bool async = false;
   bool to_file = false;
   bool to_stdout = false;
   std::string level = "debug";
   std::vector<std::pair<std::string, std::string>> levels = {
      { "ios_fs", "warn" },
   };
   std::string directory = ".";
   bool branch_trace = false;
   bool hle_trace = false;
   bool hle_trace_res = false;
   std::vector<std::string> hle_trace_filters =
   {
      "+.*",
      "-coreinit.rpl::__ghsLock",
      "-coreinit.rpl::__ghsUnlock",
      "-coreinit.rpl::__gh_errno_ptr",
      "-coreinit.rpl::__gh_set_errno",
      "-coreinit.rpl::__gh_get_errno",
      "-coreinit.rpl::__get_eh_globals",
      "-coreinit.rpl::OSGetTime",
      "-coreinit.rpl::OSGetSystemTime",
   };
};

struct SoundSettings
{
   bool dump_sounds = false;
};

enum class SystemRegion
{
   Japan = 0x01,
   USA = 0x02,
   Europe = 0x04,
   Unknown8 = 0x08,
   China = 0x10,
   Korea = 0x20,
   Taiwan = 0x40,
};

struct SystemSettings
{
   SystemRegion region = SystemRegion::Europe;
   std::string content_path = {};
   std::string hfio_path = "";
   std::string mlc_path = "mlc";
   std::string otp_path = "otp.bin";
   std::string sdcard_path = "sdcard";
   std::string resources_path = "resources";
   std::string slc_path = "slc";
   std::vector<std::string> title_directories = {};
   bool time_scale_enabled = false;
   double time_scale = 1.0;
   std::vector<std::string> lle_modules;
   bool dump_hle_rpl = false; // TODO: Move this to a debug api command?
};

struct Settings
{
   DebuggerSettings debugger;
   Gx2Settings gx2;
   LogSettings log;
   SoundSettings sound;
   SystemSettings system;
};

std::shared_ptr<const Settings> config();
void setConfig(const Settings &settings);

} // namespace decaf
