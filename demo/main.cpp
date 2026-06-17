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

tokyo {
    let vec = Vec<u8>{1, 2, 3, 4};

    Box<DbPtr> db = Box_new(DbPtr{});

    let user = get_user("アクゼスチィア");

    if (user) {
        std::println("[{}] > 東京へよこそ！ ^~^", user->name);
    }

    _ 0;
}
