cc := if os() == "macos" {
    "/opt/homebrew/opt/llvm/bin/clang"
} else {
    "/usr/bin/clang"
}

cxx := if os() == "macos" {
    "/opt/homebrew/opt/llvm/bin/clang++"
} else {
    "/usr/bin/clang++"
}

export CC := cc
export CXX := cxx

export SDKROOT := if os() == "macos" {
    `xcrun --show-sdk-path`
} else {
    ""
}

default: xpp b

xpp DEMO="OFF":
    cmake -S . -B build -G Ninja -DTOKYO_BUILD_DEMO={{DEMO}}

b:
    ninja -C build

clean:
    rm -rf build

demo:
    ./build/demo
