<div align="center">

# 東京

<img width="1200" height="702" alt="image" src="https://github.com/user-attachments/assets/0e31d8cc-8824-4bd0-9c79-524ed9df1517" />

</div>


### Make your c++ code look nice ^~^

```c++
// Without tokyo ~_~

auto main(int argc, char* argv[]) -> int {
    // Do smth
}
```

```c++
// With tokyo ^~^
#include <print>
#include <tokyo/tokyo_main.hxx>
#include <tokyo/tokyo_types.hxx>

/// ^^
fn parse(sv s) -> Result<i32, String> {
    if (s.empty())
        _ Err(String{"empty"});
    _ Ok(5);
}

struct User {
    str name;
};

fn user_exists(str name) -> bool {
    if (name == "アクゼスチィア")
        _ true;
    _ false;
}

fn get_user(str name) -> Option<User> {
    if (user_exists(name))
        _ Some(User{
            .name = name,
        });
    _ None;
}

struct DbPtr {};

// Rust, but in C++ xD
tokyo {
    let vec = Vec<u8>{1, 2, 3, 4};

    Box<DbPtr> db = Box_new(DbPtr{});

    let user = get_user("アクゼスチィア");

    if (user) {
        std::println("[{}] > 東京へよこそ！ ^~^", user->name);
    }

    _ 0;
}
```

### Install

Clone repo

```sh
gh repo clone Akzestia/tokyo
cd tokyo
```

Build 

```sh
j
# Or with demo
j xpp ON && j b
```

Install globally

```sh
j i
```
