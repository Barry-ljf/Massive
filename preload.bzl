load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def massive_preload():
  if "com_github_gflags_gflags" not in native.existing_rules():
    http_archive(
      name = "com_github_gflags_gflags",
      sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
      strip_prefix = "gflags-2.2.2",
      urls = [
          "https://github.com/gflags/gflags/archive/v2.2.2.tar.gz",
      ],
    )
    
  if "com_google_googletest" not in native.existing_rules():
    http_archive(
        name = "com_google_googletest",
        url = "https://github.com/google/googletest/archive/release-1.10.0.zip",
        sha256 = "94c634d499558a76fa649edb13721dce6e98fb1e7018dfaeba3cd7a083945e91",
        strip_prefix = "googletest-release-1.10.0",
    )

  if "com_github_glog_glog" not in native.existing_rules():
    http_archive(
        name = "com_github_glog_glog",
        url = "https://github.com/google/glog/archive/refs/tags/v0.6.0.zip",
        strip_prefix = "glog-0.6.0",
    )