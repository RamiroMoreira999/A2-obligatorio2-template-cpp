// Generado con Claude (Anthropic), revisado y probado por nosotros. Ver autoria.md.
#include <string>
#include <cstdint>

int cantSumandos;
std::string palabras[6];

int digito[26];
bool usado[10];
bool noCero[26];

char orden[10];
int cantLetras;

bool haySolucion;
int64_t mejor[6];

char letraEnColumna(std::string palabra, int col)
{
    int largo = palabra.length();
    return palabra[largo - 1 - col];
}

int64_t valorPalabra(std::string palabra)
{
    int64_t valor = 0;
    int largo = palabra.length();
    for (int i = 0; i < largo; i++)
    {
        valor = valor * 10 + digito[palabra[i] - 'A'];
    }
    return valor;
}

bool columnasOk()
{
    int acarreo = 0;
    int largoResultado = palabras[cantSumandos].length();

    for (int col = 0; col < largoResultado; col++)
    {
        int suma = acarreo;

        for (int k = 0; k < cantSumandos; k++)
        {
            int largo = palabras[k].length();
            if (col < largo)
            {
                int d = digito[letraEnColumna(palabras[k], col) - 'A'];
                if (d == -1) return true;
                suma += d;
            }
        }

        int dResultado = digito[letraEnColumna(palabras[cantSumandos], col) - 'A'];
        if (dResultado == -1) return true;

        if (suma % 10 != dResultado) return false;
        acarreo = suma / 10;
    }

    return acarreo == 0;
}

void registrarSolucion()
{
    int64_t actual[6];
    actual[0] = valorPalabra(palabras[cantSumandos]);
    for (int k = 0; k < cantSumandos; k++)
    {
        actual[k + 1] = valorPalabra(palabras[k]);
    }

    bool esMenor = false;
    if (!haySolucion)
    {
        esMenor = true;
    }
    else
    {
        bool decidido = false;
        for (int t = 0; t <= cantSumandos && !decidido; t++)
        {
            if (actual[t] != mejor[t])
            {
                esMenor = actual[t] < mejor[t];
                decidido = true;
            }
        }
    }

    if (esMenor)
    {
        haySolucion = true;
        for (int t = 0; t <= cantSumandos; t++)
        {
            mejor[t] = actual[t];
        }
    }
}

void backtracking(int i)
{
    if (i == cantLetras)
    {
        registrarSolucion();
        return;
    }

    int letra = orden[i] - 'A';
    for (int d = 0; d <= 9; d++)
    {
        bool sePuede = !usado[d] && !(d == 0 && noCero[letra]);
        if (sePuede)
        {
            digito[letra] = d;
            usado[d] = true;

            if (columnasOk())
            {
                backtracking(i + 1);
            }

            digito[letra] = -1;
            usado[d] = false;
        }
    }
}

void resolverAcertijo()
{
    for (int l = 0; l < 26; l++)
    {
        digito[l] = -1;
        noCero[l] = false;
    }
    for (int d = 0; d < 10; d++)
    {
        usado[d] = false;
    }
    haySolucion = false;

    int largoResultado = palabras[cantSumandos].length();

    for (int k = 0; k <= cantSumandos; k++)
    {
        if (palabras[k].length() > 1)
        {
            noCero[palabras[k][0] - 'A'] = true;
        }
    }

    for (int k = 0; k < cantSumandos; k++)
    {
        int largo = palabras[k].length();
        if (largo > largoResultado) return;
    }

    bool agregada[26];
    for (int l = 0; l < 26; l++)
    {
        agregada[l] = false;
    }
    cantLetras = 0;

    for (int col = 0; col < largoResultado; col++)
    {
        for (int k = 0; k <= cantSumandos; k++)
        {
            int largo = palabras[k].length();
            if (col < largo)
            {
                int letra = letraEnColumna(palabras[k], col) - 'A';
                if (!agregada[letra])
                {
                    agregada[letra] = true;
                    orden[cantLetras] = palabras[k][largo - 1 - col];
                    cantLetras++;
                }
            }
        }
    }

    backtracking(0);
}