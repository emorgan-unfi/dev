#!/usr/bin/env bash
sudo apt-get update
sudo apt-get install -qy curl wget
sudo echo insecure >> ~/.curlrc
sudo apt-get install -qy python-software-properties
sudo sed -i.bak 's/PEER, 1/PEER, 0/' /usr/lib/python2.7/dist-packages/softwareproperties/ppa.py
sudo sed -i 's/HOST, 2/HOST, 0/' /usr/lib/python2.7/dist-packages/softwareproperties/ppa.py
sudo apt-get install -qy git screen htop
sudo apt-get install -qy vsftpd 
sudo apt-get install -qy apache2 libapache2-mod-php5
sudo a2enmod rewrite
sudo apt-get install debconf-utils -qy
sudo debconf-set-selections <<< "mysql-server mysql-server/root_password password 1234" 
sudo debconf-set-selections <<< "mysql-server mysql-server/root_password_again password 1234"
sudo apt-get install -qy mysql-server-5.5 mysql-client >> /dev/null
sudo add-apt-repository ppa:ondrej/php5
sudo apt-get update
sudo apt-get install -qy php5 php5-gd php5-mysql php5-curl php5-cli php5-cgi php5-dev
sudo apt-get install -qy sendmail memcached imagemagick libcurl3-openssl-dev
sudo apt-get install -qy php-pear
sudo pecl install memcache
sudo curl -sS https://getcomposer.org/installer | php -- --disable-tls
sudo mv composer.phar /usr/local/bin/composer
mysql -uroot -p1234 --execute="CREATE DATABASE app"
mysql -uroot -p1234 --execute="CREATE USER 'vagrant'@'localhost' IDENTIFIED BY 'some_pass'"
mysql -uroot -p1234 --execute="GRANT ALL PRIVILEGES ON *.* TO 'vagrant'@'localhost' WITH GRANT OPTION"
if ! [ -L /var/www ]; then
	sudo   rm -rf /var/www
	sudo   ln -fs /vagrant /var/www
fi
if ! [ -d /var/www/html ]; then
	sudo   mkdir /var/www/html
	sudo   ln -fs /vagrant/drupal /var/www/html
else 
	sudo ln -fs /vagrant/drupal /var/www/html
fi
cd /var/www/
composer install
export PATH=/var/www/vendor/bin:$PATH
sudo echo "export PATH=\"/var/www/vendor/bin:$PATH\"" >> ~/.bashrc
drush dl drupal-7.x
sudo mv drupal-7* drupal
cd drupal
drush -qy site-install standard --account-name=admin --account-pass=admin --db-url=mysql://vagrant:some_pass@localhost/app
sudo mv /etc/apache2/sites-enabled/000-default.conf /etc/apache2/sites-enabled/000-default.conf.old
sudo mv /etc/vsftpd.conf /etc/vsftpd.conf.old
sudo cp /vagrant/files/000-default.conf /etc/apache2/sites-enabled/000-default.conf
sudo cp /vagrant/files/vsftpd.conf /etc/vsftpd.conf
sudo service apache2 restart
sudo service vsftpd restart
