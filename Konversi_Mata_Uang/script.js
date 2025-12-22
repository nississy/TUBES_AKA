// Konstanta kurs IDR ke USD
const RATE = 16615;

// Iteratif
function konversiIteratif(idr, n) {
    let total = 0;
    for (let i = 0; i < n; i++) {
        total += idr / RATE;
    }
    return total;
}

// Rekursif
function konversiRekursif(idr, n) {
    if (n <= 1) {
        return idr / RATE;
    }
    const mid = Math.floor(n / 2); // Math.floor untuk membulatkan angka ke bawah (floor) hingga menjadi bilangan bulat terdekat.
    return konversiRekursif(idr, mid) + konversiRekursif(idr, n - mid);
}

// MAIN
function hitung() {
    //document untuk merepresentasikan seluruh halaman HTML. JavaScript bisa mengakses, membaca, dan memanipulasi elemen HTML melalui document.
    //.value untuk mengambil isi yang diketik user di elemen input
    const idr = parseFloat(document.getElementById("idr").value);
    const n = parseInt(document.getElementById("n").value);

    //isNan = is not a number
    if (isNaN(idr) || isNaN(n)) {
        alert("Input IDR dan jumlah lembar IDR harus diisi!");
        return;
    }

    document.getElementById("iteratif").innerText = konversiIteratif(idr, n).toFixed(2) + " USD";
    document.getElementById("rekursif").innerText = konversiRekursif(idr, n).toFixed(2) + " USD";

     // Estimasi running time
    const rtIteratif = n;                 // O(n)
    const rtRekursif = n * Math.log2(n);  // O(n log n)

    document.getElementById("rt-iteratif").innerText = "Iteratif O(n) ≈ " + rtIteratif * 0.00001 + " s";

    document.getElementById("rt-rekursif").innerText = "Rekursif O(n log n) ≈ " + rtRekursif.toFixed(2) * 0.00001 + " s";
}

