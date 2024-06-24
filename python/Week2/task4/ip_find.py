from bs4 import BeautifulSoup as bs

number = ["0","1","2","3","4","5","6","7","8","9","."]
your_ip = ""

def find_ip(ip):
    global your_ip
    for i in range(len(ip)):
        if(ip[i] in number):
            your_ip += ip[i]

def get_ip(page):
    src = page.content
    soup = bs(src,"lxml")
    ip = soup.find("p").text
    ip = find_ip(ip)
    return str(your_ip)