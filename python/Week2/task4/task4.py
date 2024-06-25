import requests
import ip_find
import webbrowser

page = requests.get("https://api.ipify.org/?format=json")

ip = ip_find.get_ip(page)

webbrowser.open(f"https://ipinfo.io/{ip}/geo")





