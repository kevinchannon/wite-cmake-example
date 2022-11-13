// wite-cmake-example.cpp : Defines the entry point for the application.
//

#include <wite/wite.hpp>

#include <iostream>

int main()
{
  const auto words = wite::string::split("Hello Wite");

  for (const auto& word : words) {
    std::cout << word << std::endl;
  }

	return 0;
}
