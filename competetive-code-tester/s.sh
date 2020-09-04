echo "[*] gen.cc"
g++ gen.cc -o gen

echo "[*] brute.cc"
g++ brute.cc -o brute

echo "[*] prog.cc"
g++ prog.cc -o prog

for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./brute < int) <(./prog < int) || break
done

