# Mobile_APP\main.py
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
import socket

class TCPClient:
    def __init__(self):
        self.server_ip = None
        self.server_port = None
        self.client_socket = None

    def connect(self, ip, port):
        try:
            self.server_ip = ip
            self.server_port = port
            self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.client_socket.connect((self.server_ip, self.server_port))
            return True
        except Exception as e:
            print(f"Error connecting to server: {e}")
            return False

    def send_message(self, message):
        try:
            if self.client_socket:
                self.client_socket.sendall(message.encode('utf-8'))
        except Exception as e:
            print(f"Error sending message: {e}")
    
    def close(self):
        if self.client_socket:
            self.client_socket.close()
            self.client_socket = None

class TCPClientApp(App):
    def build(self):
        self.client = TCPClient()
        self.main_layout = BoxLayout(orientation='vertical', padding=10, spacing=10)

        # IP and Port input fields
        self.ip_input = TextInput(hint_text='Server IP', multiline=False)
        self.port_input = TextInput(hint_text='Server Port', multiline=False)
        self.connect_button = Button(text='Connect to Server', on_press=self.connect_to_server)

        # Add widgets to main layout
        self.main_layout.add_widget(self.ip_input)
        self.main_layout.add_widget(self.port_input)
        self.main_layout.add_widget(self.connect_button)

        return self.main_layout

    def connect_to_server(self, instance):
        ip = self.ip_input.text
        try:
            port = int(self.port_input.text)
            if self.client.connect(ip, port):
                # Remove the IP and port input fields
                self.main_layout.clear_widgets()

                # Add Main buttons
                self.open_app_button      = Button(text='Open App', on_press=self.show_app_buttons)
                self.open_link_web_button = Button(text='Open Link', on_press=self.show_links_buttons)
                self.open_terminal_button = Button(text='Terminal', on_press=self.show_terminal_controls)
                self.open_system_button   = Button(text='System', on_press=self.show_system_controls)
                self.close_server_button  = Button(text='Close Server', on_press=self.close_server)

                self.main_layout.add_widget(self.open_app_button)
                self.main_layout.add_widget(self.open_link_web_button)
                self.main_layout.add_widget(self.open_terminal_button)
                self.main_layout.add_widget(self.open_system_button)
                self.main_layout.add_widget(self.close_server_button)
            else:
                self.main_layout.add_widget(Label(text="Failed to connect. Check IP/Port."))
        except ValueError:
            self.main_layout.add_widget(Label(text="Invalid port number."))


    def show_system_controls(self, instance):
        # Clear the main layout
        self.main_layout.clear_widgets()

        # Add the system buttons
        self.shutdown_button = Button(text='Shutdown', on_press=lambda x: self.send_message('system shutdown')) 
        self.reboot_button   = Button(text='Reboot', on_press=lambda x: self.send_message('system reboot'))
        self.sleep_button    = Button(text='Sleep', on_press=lambda x: self.send_message('system sleep'))
        self.back_button     = Button(text='Back', on_press=self.show_main_controls)

        # Add all system buttons to the layout
        self.main_layout.add_widget(self.shutdown_button)
        self.main_layout.add_widget(self.reboot_button)
        self.main_layout.add_widget(self.sleep_button)
        self.main_layout.add_widget(self.back_button)

    def show_app_buttons(self, instance):
        # Clear the main layout
        self.main_layout.clear_widgets()

        # Add the application buttons
        self.edge_button = Button(text='Edge', on_press=lambda x: self.send_message('edge'))
        self.chrome_button = Button(text='Chrome', on_press=lambda x: self.send_message('chrome'))
        self.vscode_button = Button(text='VSCode', on_press=lambda x: self.send_message('vsCode'))
        self.microchip_button = Button(text='Microchip Studio', on_press=lambda x: self.send_message('microchip'))
        self.stm_cube_button = Button(text='STM Cube', on_press=lambda x: self.send_message('stmcube'))
        self.stm_utility_button = Button(text='STM Utility', on_press=lambda x: self.send_message('stmutility'))
        self.virtualbox_button = Button(text='VirtualBox', on_press=lambda x: self.send_message('virtualbox'))
        self.whatsapp_button = Button(text='Whats App', on_press= self.whatsapp)
        self.back_button = Button(text='Back', on_press=self.show_main_controls)

        # Add all application buttons to the layout
        self.main_layout.add_widget(self.edge_button)
        self.main_layout.add_widget(self.chrome_button)
        self.main_layout.add_widget(self.vscode_button)
        self.main_layout.add_widget(self.microchip_button)
        self.main_layout.add_widget(self.stm_cube_button)
        self.main_layout.add_widget(self.stm_utility_button)
        self.main_layout.add_widget(self.virtualbox_button)
        self.main_layout.add_widget(self.whatsapp_button)
        self.main_layout.add_widget(self.back_button)

    def show_links_buttons(self, instance):
        # Clear the main layout
        self.main_layout.clear_widgets()

        # Add the application buttons
        self.youtube_button = Button(text='Youtube', on_press=self.Youtube)
        self.github_button = Button(text='GitHub', on_press=lambda x: self.send_message('github'))
        self.facebook_button = Button(text='Facebook', on_press=lambda x: self.send_message('facebook'))
        self.twitter_button = Button(text='Twitter', on_press=lambda x: self.send_message('twitter'))
        self.instagram_button = Button(text='Instagram', on_press=lambda x: self.send_message('instagram'))
        self.linkedin_button = Button(text='Linkedin', on_press=lambda x: self.send_message('linkedin'))
        self.pinterest_button = Button(text='Pinterest', on_press=lambda x: self.send_message('pinterest'))
        self.tiktok_button = Button(text='Tiktok', on_press=lambda x: self.send_message('tiktok'))
        self.reddit_button = Button(text='Reddit', on_press=lambda x: self.send_message('reddit'))
        self.back_button = Button(text='Back', on_press=self.show_main_controls)

        # Add all application buttons to the layout
        self.main_layout.add_widget(self.youtube_button)
        self.main_layout.add_widget(self.github_button)
        self.main_layout.add_widget(self.facebook_button)
        self.main_layout.add_widget(self.twitter_button)
        self.main_layout.add_widget(self.instagram_button)
        self.main_layout.add_widget(self.linkedin_button)
        self.main_layout.add_widget(self.tiktok_button)
        self.main_layout.add_widget(self.pinterest_button)
        self.main_layout.add_widget(self.reddit_button)
        self.main_layout.add_widget(self.back_button)
    
    def show_terminal_controls(self, instance):
        # Clear the main layout
        self.send_message("terminal")
        self.main_layout.clear_widgets()

        # Add the application buttons
        self.terminal_input = TextInput(hint_text='Command', multiline=False)
        self.send_terminal_button = Button(text='Send', on_press = self.handler_terminal)
        self.back_button = Button(text='Back', on_press=self.show_main_controls)

        # Add all application buttons to the layout
        self.main_layout.add_widget(self.terminal_input)
        self.main_layout.add_widget(self.send_terminal_button)
        self.main_layout.add_widget(self.back_button)

    def handler_terminal(self, instance):
        # Get the text from the TextInput
        cmd = self.terminal_input.text.strip()

        if cmd:
            # If the user wrote something, send the search query
            self.send_message("terminal " + cmd)
        else:
            # If the user wrote nothing, send "YouTube"
            self.send_message("terminal")

    def Youtube(self, instance):
        self.main_layout.clear_widgets()

        # Create the TextInput for searching
        self.youtube_search = TextInput(hint_text='Search', multiline=False)

        # Create the Search button and bind it to the new function `handle_search`
        self.search = Button(text='Search', on_press=self.handle_search)
        
        # Back to previous page
        self.pre_you_button = Button(text='Back', on_press=self.show_links_controls)

        # Add the TextInput and the Button to the layout
        self.main_layout.add_widget(self.youtube_search)
        self.main_layout.add_widget(self.search)
        self.main_layout.add_widget(self.pre_you_button)

    def handle_search(self, instance):
        # Get the text from the TextInput
        query = self.youtube_search.text.strip()

        if query:
            # If the user wrote something, send the search query
            self.send_message("youtube " + query)
        else:
            # If the user wrote nothing, send "YouTube"
            self.send_message("youtube")

    def whatsapp(self, instance):
        self.main_layout.clear_widgets()

        # Create the TextInput for searching
        self.phone = TextInput(hint_text='Phone Number', multiline=False)

        # Create the Search button and bind it to the new function `handle_search`
        self.open = Button(text='open', on_press=self.handle_whatsapp)
        
        # Back to previous page
        self.pre_wa_button = Button(text='Back', on_press=self.show_app_controls)

        # Add the TextInput and the Button to the layout
        self.main_layout.add_widget(self.phone)
        self.main_layout.add_widget(self.open)
        self.main_layout.add_widget(self.pre_wa_button)

    def handle_whatsapp(self, instance):
        # Get the text from the TextInput
        number = self.phone.text.strip()

        if number:
            # If the user wrote something, send the search query
            self.send_message("Whatsapp " + number)
        else:
            # If the user wrote nothing, send "WhatsApp"
            self.send_message("whatsapp")


    def show_main_controls(self, instance):
        # Clear the main layout and add the "Open App" and "Close Server" buttons back
        self.main_layout.clear_widgets()
        self.main_layout.add_widget(self.open_app_button)
        self.main_layout.add_widget(self.open_link_web_button)
        self.main_layout.add_widget(self.open_terminal_button)
        self.main_layout.add_widget(self.open_system_button)
        self.main_layout.add_widget(self.close_server_button)

    def show_app_controls(self, instance):
        # Clear the main layout and add the buttons back
        self.main_layout.clear_widgets()
        self.main_layout.add_widget(self.edge_button)
        self.main_layout.add_widget(self.chrome_button)
        self.main_layout.add_widget(self.vscode_button)
        self.main_layout.add_widget(self.microchip_button)
        self.main_layout.add_widget(self.stm_cube_button)
        self.main_layout.add_widget(self.stm_utility_button)
        self.main_layout.add_widget(self.virtualbox_button)
        self.main_layout.add_widget(self.whatsapp_button)
        self.main_layout.add_widget(self.back_button)

    def show_links_controls(self, instance):
        # Clear the main layout and add the buttons back
        self.main_layout.clear_widgets()
        self.main_layout.add_widget(self.youtube_button)
        self.main_layout.add_widget(self.github_button)
        self.main_layout.add_widget(self.facebook_button)
        self.main_layout.add_widget(self.twitter_button)
        self.main_layout.add_widget(self.instagram_button)
        self.main_layout.add_widget(self.linkedin_button)
        self.main_layout.add_widget(self.tiktok_button)
        self.main_layout.add_widget(self.pinterest_button)
        self.main_layout.add_widget(self.reddit_button)
        self.main_layout.add_widget(self.back_button)

    def send_message(self, message):
        self.client.send_message(message)

    def close_server(self, instance):
        self.client.send_message('close')
        self.client.close()
        App.get_running_app().stop()

if __name__ == '__main__':
    TCPClientApp().run()
