#!/bin/bash

PROG="./push_swap"
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
BOLD='\033[1m'
NC='\033[0m'

clear
if [ ! -f "$PROG" ]; then
    echo -e "${RED}Error: Ejecutable '$PROG' no encontrado. Haz 'make' primero.${NC}"
    exit 1
fi

echo -e "${BLUE}${BOLD}====================================================${NC}"
echo -e "${BLUE}${BOLD}       🚀 TESTER DEFINITIVO PUSH_SWAP 🚀          ${NC}"
echo -e "${BLUE}${BOLD}====================================================${NC}\n"

# Variables para conteo
OK_TOTAL=0
KO_TOTAL=0

# Función principal de testeo
# $1: Tipo esperado (ERROR, SILENT, VALID)
# $2: Descripción
# $3: Argumentos (literal como se escribiría en terminal)
run_test() {
    expected=$1
    desc=$2
    args=$3

    # Ejecutamos aislando stdout y stderr en archivos temporales
    bash -c "$PROG $args" > .test_out 2> .test_err
    exit_code=$?

    out_content=$(cat .test_out)
    err_content=$(cat .test_err)

    if [ $exit_code -eq 139 ] || [ $exit_code -eq 11 ]; then
        echo -e "${RED}[KO]${NC} $desc ${YELLOW}(¡SEGFAULT!)${NC}"
        ((KO_TOTAL++))
        return
    fi

    if [ "$expected" == "ERROR" ]; then
        # Comprobamos que ponga "Error" y que lo haga en STDERR, no en STDOUT
        if grep -q "Error" .test_err; then
            if [ -n "$out_content" ]; then
                echo -e "${RED}[KO]${NC} $desc ${YELLOW}(Imprimió Error en stderr, pero también imprimió cosas en stdout)${NC}"
                ((KO_TOTAL++))
            else
                echo -e "${GREEN}[OK]${NC} $desc"
                ((OK_TOTAL++))
            fi
        else
            echo -e "${RED}[KO]${NC} $desc ${YELLOW}(Esperaba Error en stderr. out='$out_content' | err='$err_content')${NC}"
            ((KO_TOTAL++))
        fi

    elif [ "$expected" == "SILENT" ]; then
        if [ -z "$out_content" ] && [ -z "$err_content" ]; then
            echo -e "${GREEN}[OK]${NC} $desc"
            ((OK_TOTAL++))
        else
            echo -e "${RED}[KO]${NC} $desc ${YELLOW}(Esperaba silencio. out='$out_content' | err='$err_content')${NC}"
            ((KO_TOTAL++))
        fi

    elif [ "$expected" == "VALID" ]; then
        if grep -q "Error" .test_err; then
            echo -e "${RED}[KO]${NC} $desc ${YELLOW}(Dio Error en un caso válido. err='$err_content')${NC}"
            ((KO_TOTAL++))
        else
            echo -e "${GREEN}[OK]${NC} $desc"
            ((OK_TOTAL++))
        fi
    fi
}

echo -e "${BOLD}--- 1. PRUEBAS DE SILENCIO (Sin output ni errores) ---${NC}"
run_test "SILENT" "Sin parámetros" ""
run_test "SILENT" "Un solo número" "42"
run_test "SILENT" "Lista ya ordenada simple" "1 2 3 4 5"
run_test "SILENT" "Lista ordenada con negativos" "-10 -5 0 5 10"
run_test "SILENT" "Lista ordenada en string" '" 1   2  3"'
echo ""

echo -e "${BOLD}--- 2. PRUEBAS DE ERROR SINTÁCTICO (Debe salir Error por STDERR) ---${NC}"
run_test "ERROR" "Letras sueltas" "a b c"
run_test "ERROR" "Letra escondida entre números" "1 2 3a 4"
run_test "ERROR" "Símbolos especiales" "1 2 % 4"
run_test "ERROR" "Solo un guion" "-"
run_test "ERROR" "Solo un signo más" "+"
run_test "ERROR" "Signo después del número" "1 2 3- 4"
run_test "ERROR" "Doble signo" "1 2 ++3 4"
run_test "ERROR" "String vacío" '""'
run_test "ERROR" "String de solo espacios" '"    "'
run_test "ERROR" "Argumento válido mezclado con string vacío" '1 2 "" 3'
echo ""

echo -e "${BOLD}--- 3. LÍMITES MATEMÁTICOS (Debe salir Error por STDERR) ---${NC}"
run_test "ERROR" "INT_MAX + 1 (Overflow)" "2147483648"
run_test "ERROR" "INT_MIN - 1 (Underflow)" "-2147483649"
run_test "ERROR" "Número absurdamente grande" "999999999999999999"
run_test "ERROR" "Overflow oculto en un string" '"1 2 99999999999 3"'
echo ""

echo -e "${BOLD}--- 4. DUPLICADOS (Debe salir Error por STDERR) ---${NC}"
run_test "ERROR" "Duplicado simple" "1 2 3 1"
run_test "ERROR" "Duplicados negativos" "-5 2 3 -5"
run_test "ERROR" "Cero y otro cero" "0 0"
run_test "ERROR" "Cero y +0 (son el mismo número)" "0 +0"
run_test "ERROR" "Duplicado oculto en string" '"1 2 3 2"'
echo ""

echo -e "${BOLD}--- 5. PARSEO EXTREMO (Debe funcionar SIN Error) ---${NC}"
run_test "VALID" "Lista desordenada (debe imprimir comandos)" "3 2 1"
run_test "VALID" "Límites enteros exactos" "2147483647 -2147483648 0"
run_test "VALID" "Signos positivos explícitos" "+1 +2 +3"
run_test "VALID" "Ceros a la izquierda" "00001 0002 -0003 +004"
run_test "VALID" "Muchos espacios en string" '"   3    -2      +1   "'
run_test "VALID" "Mezcla de ints y strings" '1 "2 3" 4 "-5 6"'
run_test "VALID" "Solo números negativos" "-1 -2 -3 -4"
run_test "VALID" "Alternando positivos y negativos" "5 -4 3 -2 1"
run_test "VALID" "Strings individuales con negativos" '"-1" "-2" "-3"'
run_test "ERROR" "Cero negativo y ceros" "-0 5 00" # -0 evalúa a 0, 00 evalúa a 0. ¡Debería dar DUPLICADO!
run_test "VALID" "Signos explícitos válidos" "+5 -5 4 -4" # +5 y -5 son distintos
run_test "VALID" "Negativos con espacios alrededor" '" -5 " " 3 "'
echo ""

echo -e "${BOLD}--- 6. FLAGS Y CONFLICTOS ---${NC}"
run_test "ERROR" "Flag inexistente (debe detectarse como invalido)" "--invent 1 2 3"
run_test "ERROR" "Conflicto de algoritmos" "--simple --medium 1 2 3"
run_test "VALID" "Flag simple válido" "--simple 3 2 1"
run_test "VALID" "Multi flags compatibles" "--bench --simple 3 2 1"
echo ""

# Limpieza
rm -f .test_out .test_err

echo -e "${BLUE}${BOLD}====================================================${NC}"
echo -e "RESULTADOS: ${GREEN}$OK_TOTAL OK${NC} | ${RED}$KO_TOTAL KO${NC}"
if [ $KO_TOTAL -eq 0 ]; then
    echo -e "${GREEN}¡Enhorabuena! El parseo es perfecto y cumple las normas de 42 al milímetro.${NC}"
else
    echo -e "${RED}Aún tienes detalles que pulir. Revisa los [KO] de arriba.${NC}"
fi
