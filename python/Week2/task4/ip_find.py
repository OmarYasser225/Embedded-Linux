from bs4 import BeautifulSoup as bs

def get_ip(page):
    src = page.content
    soup = bs(src,"lxml")
    ip = soup.find("p").text[7:-2]
    print(ip)
    return str(ip)