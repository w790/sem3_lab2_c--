#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

// Читаем IP из строки "a.b.c.d" и возвращаем кортеж (a, b, c, d)
std::tuple<int, int, int, int> parse_ip(const std::string& ip_str) {
    int a, b, c, d;
    char dot1, dot2, dot3;
    std::sscanf(ip_str.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
    return std::make_tuple(a, b, c, d);
}

int main() {
    std::vector<std::string> ips;
    std::string line;

    // Читаем строки из stdin
    while (std::getline(std::cin, line)) {
        auto pos = line.find('\t');
        std::string ip = line.substr(0, pos);
        ips.push_back(ip);
    }

    // Сортируем IP в обратном порядке
    std::sort(ips.begin(), ips.end(), [](const auto& a, const auto& b) {
        auto ip1 = parse_ip(a);
        auto ip2 = parse_ip(b);
        return ip1 > ip2;  // сравниваем кортежи
    });

    // Выводим все IP
    for (const auto& ip : ips) {
        std::cout << ip << std::endl;
    }

    // 2. Вывод адресов с первым байтом = 1
    std::cout << " first byte = 1:" << std::endl;
    for (const auto& ip : ips) {
        auto [a, b, c, d] = parse_ip(ip);  // C++17: разбор кортежа на переменные
        if (a == 1) {
            std::cout << ip << std::endl;
        }
    }

    // 3. Вывод адресов: первый байт = 46, второй = 70
    std::cout << "IPs with first byte = 46, second = 70:" << std::endl;
    for (const auto& ip : ips) {
        auto [a, b, c, d] = parse_ip(ip);
        if (a == 46 && b == 70) {
            std::cout << ip << std::endl;
        }
    }

    // 4. Вывод адресов с любым байтом = 46
    std::cout << "IPs with any byte = 46:" << std::endl;
    for (const auto& ip : ips) {
        auto [a, b, c, d] = parse_ip(ip);
        if (a == 46 || b == 46 || c == 46 || d == 46) {
            std::cout << ip << std::endl;
        }
    }

    return 0;
    // Далее фильтруем и выводим остальные списки...
}
// ДЛЯ ТЕСТА
// 1.1.1.1\tignore1\tignore2
// 1.2.1.1\tignore3\tignore4
// 1.10.1.1\tignore5\tignore6
// 46.70.1.1\tignore7\tignore8
// 46.71.46.1\tignore9\tignore10
// 192.168.1.46\tignore11\tignore12