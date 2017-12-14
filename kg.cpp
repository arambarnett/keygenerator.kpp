#include <random>
#include <iostream>
#include <string>
using namespace std;

string r_Output = "K";

int
main ()
{
  constexpr char chset[] =
    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  auto r_char =
    [ =, r_gen { std::mt19937 {std::random_device {} ()} }] ()mutable {
    return chset[std::uniform_int_distribution <> {0, sizeof chset - 1}
(r_gen)];
  };

  for (auto i = 0; i < 52; ++i)
    r_Output += r_char ();

  std::cout << r_Output;
}
