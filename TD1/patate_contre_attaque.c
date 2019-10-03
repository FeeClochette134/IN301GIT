./alea.c > nombres.data
sort -n nombres.data > nombres_tries.data
uniq nombres_tries.data > nombres.uniq.data
wc -l nombres.uniq.data
