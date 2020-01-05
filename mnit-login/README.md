# MNIT portal auto-login
If you want to do the same just follow these procedures

- Install selenium
```
pip install selenium
```

- Download gecko drivers frome [here](https://github.com/mozilla/geckodriver/releases).

- Now, extract and copy it to `/usr/bin`
```
mv geckodriver /usr/bin
```

- Change `2017kucpxxxx` to your `id` and `xxpasswordxx` to your `password` in the [file](auto-login)

## Finally, Run the script by either -

```
python3 auto-login
```
or
```
sh auto-login
```
---
You can also make it autologin on network detection by placing the file in /etc/network/if-up.d and making it executable
