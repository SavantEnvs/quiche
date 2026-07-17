// The sanctioned build-time LeakSanitizer off-switch (SPEC §6.2 item 15).
//
// Defining this hook to return nonzero turns off ONLY the end-of-process leak check; ASan and UBSan
// stay fully active (memory-safety and UB reports still abort the run). It overrides the weak
// default the sanitizer runtime provides.
//
// Built by mayhem/build.sh (outside Bazel, with the same $CXXFLAGS/$SANITIZER_FLAGS as the harness)
// and linked via --linkopt into //quiche:http_frame_fuzzer, i.e. /mayhem/http_frame_fuzzer and its
// copy /mayhem/http_frame_fuzzer-standalone. The non-sanitized test oracle
// (//quiche:http2_frame_decoder_test) does not need it.
extern "C" int __lsan_is_turned_off() { return 1; }
