#include <iostream>
#include <cstring> // Include for strlen
using namespace std;

// Função para obfuscar o texto usando XOR com ponteiros
void obfuscateXOR(const char* input, char* output, char key) {
    for (size_t i = 0; i < strlen(input); ++i) {
        *(output + i) = *(input + i) ^ key; // Aplica a operação XOR usando ponteiros
    }
    *(output + strlen(input)) = '\0'; // Adiciona o terminador de string
}

// Função para verificar se a obfuscação do input é igual à obfuscação do texto esperado
bool verificarObfuscacao(const char* input, const char* esperado, char key) {
    char obfuscatedInput[100];
    char obfuscatedExpected[100];

    // Obfuscação do input
    obfuscateXOR(input, obfuscatedInput, key);
    // Obfuscação do texto esperado
    obfuscateXOR(esperado, obfuscatedExpected, key);

    // Comparação
    return strcmp(obfuscatedInput, obfuscatedExpected) == 0; // Retorna true se iguais
}

int main() {
    char line[100]; // Buffer size
    cout << "say something: ";
    cin.get(line, 100); // Read input

    // Output original input
    cout << "Input: " << line << endl; // Output input line

    // Comparação secreta usando a função de verificação
    const char* original = "chave"; // Texto esperado
    char key = 'K'; // Chave para a cifra XOR
    bool result = verificarObfuscacao(line, original, key); // Chama a função de verificação

    // Output do resultado da comparação
    cout << "Comparison result: " << (result ? "true" : "false") << endl;
}