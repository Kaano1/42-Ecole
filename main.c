#include "./include/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;

	if(ac == 2 && !ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 5))
	{
		map = design_map(av[1]);
		// get_next_line ile satırlar alacağız, o sırada NO, SO, WE, EA kontrolleri yapmamız gerekiyor. F ve C leride alacağız sayı bulunan kısmı atoi ile almamız gerekiyor
		// t_pix türündeki değişkenlerimize aldığımız değerleri eklememiz gerekiyor. mapin en altta olduğunu garanti etmemiz aynı zamanda herhangi farklı bir karakter geçmediğinden
		// emin olmamız gerekiyor. ardından verilen pathlerin var olup olmadığının kontrolü sağlanacak herhangi bir kontrol sıkıntılı ise sdrerr fd = 2 olarak hata mesajı bastırılacak
		// aynı zaman freelme işlemleri olacak ve exit komutu ile sonlandırılacak.
		// renderlama ekranı yenileme işlemi yaparken herşeyi sildikten sonra yada başlarken başta ekranın yarı yarı boyuyoruz bize verilen renkler ile.
		// notionda notlar.

		// dosyanın içerisinde okuduğumuz veriye ek olarak hangi bilgileri tutmamız gerekiyor?
		// matematik kısmındaki raycasting tam olarak nasıl bir işlem yapıyor?
	}
	else
		ft_putstr_fd("Error\nArgument Error\n", 2);
}