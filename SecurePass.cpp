#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum PasswordStrength {
    WEAK,
    MEDIUM,
    STRONG
};

// Check password length
bool checkLength(const string& password) {
    return password.length() >= 8;
}

// Check if password contains uppercase letters
bool checkUppercase(const string& password) {
    for (char c : password) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

// Check if password contains lowercase letters
bool checkLowercase(const string& password) {
    for (char c : password) {
        if (islower(c)) {
            return true;
        }
    }
    return false;
}

// Check if password contains numbers
bool checkNumbers(const string& password) {
    for (char c : password) {
        if (isdigit(c)) {
            return true;
        }
    }
    return false;
}

// Check if password contains special characters
bool checkSpecialCharacters(const string& password) {
    for (char c : password) {
        if (! isalnum(c)) {
            return true;
        }
    }
    return false;
}

// Estimate password strength
PasswordStrength estimatePasswordStrength(const string& password) {
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
    string password;
    cout << "Enter a password: ";
    cin >> password;

    PasswordStrength strength = estimatePasswordStrength(password);

    cout << "Password Strength: ";
    switch (strength) {
        case WEAK:
            cout << "Weak" << endl;
            break;
        case MEDIUM:
            cout << "Medium" <<endl;
            break;
        case STRONG:
            cout << "Strong" <<endl;
            break;
    }

    return 0;
}
