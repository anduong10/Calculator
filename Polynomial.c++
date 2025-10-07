#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
private:
    vector<int> terms;

public:
    int linearTerm;
    int quadraticTerm;

    Polynomial(int constant, int linear, int quadratic) {
        linearTerm = linear;
        quadraticTerm = quadratic;
        terms.push_back(constant);   
        terms.push_back(linear);     
        terms.push_back(quadratic);  
    }

    Polynomial(const vector<int>& inputTerms) {
        terms = inputTerms;
    }

    Polynomial operator+(const Polynomial& other) {
        int maxSize;
        if (terms.size() > other.terms.size()) {
            maxSize = terms.size();
        } else {
            maxSize = other.terms.size();
        }

        vector<int> sumTerms(maxSize, 0);

        for (int i = 0; i < maxSize; i++) {
            int thisTerm = 0;
            int otherTerm = 0;

            if (i < terms.size()) {
                thisTerm = terms[i];
            }

            if (i < other.terms.size()) {
                otherTerm = other.terms[i];
            }

            sumTerms[i] = thisTerm + otherTerm;
        }

        return Polynomial(sumTerms);
    }

    Polynomial operator-(const Polynomial& other) {
        int maxSize;
        if (terms.size() > other.terms.size()) {
            maxSize = terms.size();
        } else {
            maxSize = other.terms.size();
        }

        vector<int> diffTerms(maxSize, 0);

        for (int i = 0; i < maxSize; i++) {
            int thisTerm = 0;
            int otherTerm = 0;

            if (i < terms.size()) {
                thisTerm = terms[i];
            }

            if (i < other.terms.size()) {
                otherTerm = other.terms[i];
            }

            diffTerms[i] = thisTerm - otherTerm;
        }

        return Polynomial(diffTerms);
    }

    Polynomial operator*(const Polynomial& other) {
        int productSize = terms.size() + other.terms.size() - 1;
        vector<int> productTerms(productSize, 0);

        for (int i = 0; i < terms.size(); i++) {
            for (int j = 0; j < other.terms.size(); j++) {
                productTerms[i + j] += terms[i] * other.terms[j];
            }
        }

        return Polynomial(productTerms);
    }

    void displaySum() {
        for (int i = terms.size() - 1; i >= 0; i--) {
             cout << terms[i];
            if (i > 1) {
                cout << "x^" << i;
            } else if (i == 1) {
                cout << "x";
            }

            if (i != 0) {
                cout << " + ";
            }
        }
        cout << endl;
    }

    void displaySubtraction() {
        for (int i = terms.size() - 1; i >= 0; i--) {
              cout << terms[i];
            if (i > 1) {
                cout << "x^" << i;
            } else if (i == 1) {
                cout << "x";
            }

            if (i != 0) {
                cout << " + ";
            }
        }
        cout << endl;
    }
    void displayMultiplication() {
        for (int i = terms.size() - 1; i >= 0; i--) {
            cout << terms[i];
            if (i > 1) {
                cout << "x^" << i;
            } else if (i == 1) {
                cout << "x";
            }

            if (i != 0) {
                cout << " + ";
            }
        }
        cout << endl;
    }
};



int main() {
    Polynomial poly1(5, 4, 3);
    Polynomial poly2(5, 2, 1);

    Polynomial sum = poly1 + poly2;
    Polynomial difference = poly1 - poly2;
    Polynomial product = poly1 * poly2;

    sum.displaySum();
    difference.displaySubtraction();
    product.displayMultiplication();

    return 0;
}