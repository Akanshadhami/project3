#include <iostream>
#include <string>
#include <vector>

enum PasswordStrength {
    WEAK,
    MEDIUM,
    STRONG
};

// Check password length
bool checkLength(const std::string& password) {
    return password.length() >= 8;
}

// Check if password contains uppercase letters
bool checkUppercase(const std::string& password) {
    for (char c : password) {
        if (std::isupper(c)) {
            return true;
        }
    }
    return false;
}

// Check if password contains lowercase letters
bool checkLowercase(const std::string& password) {
    for (char c : password) {
        if (std::islower(c)) {
            return true;
        }
    }
    return false;
}

// Check if password contains numbers
bool checkNumbers(const std::string& password) {
    for (char c : password) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

// Check if password contains special characters
bool checkSpecialCharacters(const std::string& password) {
    for (char c : password) {
        if (!std::isalnum(c)) {
            return true;
        }
    }
    return false;
}

// Estimate password strength
PasswordStrength estimatePasswordStrength(const std::string& password) {
    bool hasLength = checkLength(password);
    bool hasUppercase = checkUppercase(password);
    bool hasLowercase = checkLowercase(password);
    bool hasNumbers = checkNumbers(password);
    bool hasSpecialCharacters = checkSpecialCharacters(password);

    if (hasLength && hasUppercase && hasLowercase && hasNumbers && hasSpecialCharacters) {
        return STRONG;
    } else if (hasLength && ((hasUppercase && hasLowercase) || (hasUppercase && hasNumbers) || (hasLowercase && hasNumbers))) {
        return MEDIUM;
    } else {
        return WEAK;
    }
}

int main() {
    std::string password;
    std::cout << "Enter a password: ";
    std::cin >> password;

    PasswordStrength strength = estimatePasswordStrength(password);

    std::cout << "Password Strength: ";
    switch (strength) {
        case WEAK:
            std::cout << "Weak" << std::endl;
            break;
        case MEDIUM:
            std::cout << "Medium" << std::endl;
            break;
        case STRONG:
            std::cout << "Strong" << std::endl;
            break;
    }

    return 0;
}