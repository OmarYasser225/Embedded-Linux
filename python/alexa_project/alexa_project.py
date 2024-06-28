import main_function 



while True:
    text = main_function.listen()
    main_function.text_recognation(text)
    
    main_function.speak("Do you want another service")
    text = str(main_function.listen())
    check_service = main_function.check_agree_or_not(text)
    
    if(check_service == 0):
        main_function.speak("ok ,goodbye")
        break
    else:
        main_function.speak("ok, I am here. Tell me what you want")

    
