project(protobuf)

add_library(protobuf_static STATIC
    "upstream.patched/src/google/protobuf/extension_set.cc"
	"upstream.patched/src/google/protobuf/generated_message_util.cc"
	"upstream.patched/src/google/protobuf/io/coded_stream.cc"
	"upstream.patched/src/google/protobuf/io/zero_copy_stream.cc"
	"upstream.patched/src/google/protobuf/io/zero_copy_stream_impl.cc"
	"upstream.patched/src/google/protobuf/io/zero_copy_stream_impl_lite.cc"
	"upstream.patched/src/google/protobuf/message_lite.cc"
	"upstream.patched/src/google/protobuf/repeated_field.cc"
	"upstream.patched/src/google/protobuf/stubs/common.cc"
	"upstream.patched/src/google/protobuf/stubs/once.cc"
	"upstream.patched/src/google/protobuf/wire_format_lite.cc"
)

target_compile_definitions(protobuf_static
	PUBLIC
		-DGOOGLE_PROTOBUF_NO_RTTI
)
target_include_directories(protobuf_static
	PRIVATE
		"."
	PUBLIC
		"upstream.patched/src"
)
