package main

import (
	"fmt"
	"html/template"
	"net/http"
)

// Struct untuk di-passing ke template
type Result struct {
	Show     bool
	Iteratif float64
	Rekursif float64
}

// ===============================
// Iteratif O(n)
// ===============================
func KonversiIteratif(idr float64, rate float64, n int) float64 {
	temp := 0.0
	for i := 0; i < n; i++ {
		temp += idr / rate
	}
	return temp
}

// ===============================
// Rekursif O(n log n)
// ===============================
func KonversiRekursifNLogN(idr float64, rate float64, n int) float64 {
	if n <= 1 {
		return idr / rate
	}
	mid := n / 2
	left := KonversiRekursifNLogN(idr, rate, mid)
	right := KonversiRekursifNLogN(idr, rate, n-mid)
	return left + right
}

func main() {
	// Membaca file index.html
	tpl := template.Must(template.ParseFiles("index.html"))

	// Serve style.css
	http.HandleFunc("/style.css", func(w http.ResponseWriter, r *http.Request) {
		http.ServeFile(w, r, "style.css")
	})

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {

		if r.Method == "POST" {

			var idr float64
			var n int

			// Konversi
			fmt.Sscan(r.FormValue("idr"), &idr)
			fmt.Sscan(r.FormValue("n"), &n)

			rate := 16.615

			data := Result{
				Show:     true,
				Iteratif: KonversiIteratif(idr, rate, n),
				Rekursif: KonversiRekursifNLogN(idr, rate, n),
			}

			tpl.Execute(w, data)
			return
		}

		// Without POST → no results shown
		tpl.Execute(w, Result{})
	})

	fmt.Println("Server jalan di http://localhost:8080")
	http.ListenAndServe(":8080", nil)
}
