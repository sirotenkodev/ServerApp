#include <iostream>
#include <fstream>
#include <string>

#include "httplib.h"

using namespace httplib;
using namespace std;

static int counter = 0;

int main()
{
    Server svr;
    svr.set_base_dir("./");
    if (!svr.set_mount_point("/about", "./public/about")) {
      cout << "The specified base directory doesn't exist...";
      return 1;
    }
    if (!svr.set_mount_point("/", "./public/index") || !svr.set_mount_point("/index", "./public/index")) {
      cout << "The specified base directory doesn't exist...";
      return 1;
    }

    if (!svr.set_mount_point("/todos", "./public/todos")) {
      cout << "The specified base directory doesn't exist...";
      return 1;
    }

    svr.Get("/todos", [&](const auto& /*req*/, auto& res) {
        res.set_content("Count task: " + to_string(counter++), "text/html");
    });

    svr.Post("/todos/post", [&](const auto& /*req*/, auto& res) {
        res.set_content("Count task: " + to_string(counter++), "text/html");
    });

    svr.listen("localhost", 8888);
    return 0;
}
