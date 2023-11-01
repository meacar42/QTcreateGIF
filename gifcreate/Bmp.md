# Bmp(Bitmap) 

- BMP resim formatları görüntünü kalitesenin yüksek şekilde tutulduğu resim formatlarıdır
- Kalite yüksek olduğundan dolayı sıkıştırılamazlar.
- Aslen windows için oluşturulmuştur.
- Resmin her pikseli ayrı bir şekilde tanımlandığı için kalitesi fazladır.
- Pikselin rengi dosyanın paletindeki bir dizi renk değeriyle belirlenir.
- Renkler herbir pikselde saklanır 24 bit renk derinliği varsa 8,8,8 olarak ayrılır


# Yapıları

- yapısı 2 lik yapıdır  16 lık tabandaki değerlerle ifade edilir.
- Dosya başladığı = ilk 2 bayt hexadecimal olarak belirlenir.
- DIB başlağın = resmin teknik özellikleri tanımlanır(genişlik,yükseklik, renk düzeyi,sıkıştırma türü,reim boytu, renk paleti,vb).
- Renk paleti = kullanılan renklerin tanımını verir.
- Piksel verisi = resmin her bir pikselinin rengini tanımlayan bilgiyi içerir.


> ###  psudeclass 
>Renkler renk paletinde sakalanır
Her bir piksel, bu paletten bir renk indeksi ile ifade edilir.
Bu format genellikle resmi sıkıştırmak ve dosya boyutunu azaltmak için kullanılır.
GIF ve PNG gibi formatlar paletli resim formatına örnektir.

