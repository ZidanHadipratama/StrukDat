const mhs = {
    "nama": null,
    "angkatan": null,
    "jurusan": null,
    "NRP": null
}

const dataMhs = []

function maba(){
    const nama = prompt("Masukkan Nama: ")
    const akg = prompt("Masukkan Tahun Angkatan: ")
    const jurusan = prompt("Masukkan Asal Jurusan: ")
    const NRP = prompt("Masukkan NRP: ")
    
    const mhsBaru = {...mhs}
    
    mhsBaru["nama"] = nama;
    mhsBaru["angkatan"] = akg;
    mhsBaru["jurusan"] = jurusan;
    mhsBaru["NRP"] = NRP
    
    return mhsBaru;
}

function show(obj){
    console.log("===Data Mahasiswa "+ obj['nama'] +"===")
    console.log("Nama: "+obj["nama"])
    console.log("Angkatan: "+obj["angkatan"])
    console.log("Jurusan: "+obj["jurusan"])
    console.log("NRP: "+obj["NRP"])
}

function showAll(arr){
    for (let i=0;i<arr.length;i++){
        show(arr[i])
    }
}

function app(data){
    console.log("===Data Mahasiswa===")
    console.log("1. Tambah data mahasiswa")
    console.log("2. Tampilkan data mahasiswa")
    const pilihan = prompt("Berikan pilihan: ")
    if (pilihan == "1"){
        dataMhs.push(maba())
        app()
    }else{
        showAll(dataMhs)
        app()
    }
}

app()
