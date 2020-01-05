#! /usr/bin/python3

from selenium import webdriver
import selenium.webdriver.support.ui as ui

driver = webdriver.Firefox()
wait = ui.WebDriverWait(driver, 10)
driver.get('http://172.16.1.3:8002/')
wait.until(lambda driver: driver.find_element_by_xpath('//*[@id="loginbox"]/table/tbody/tr[2]/td[2]/input'))
login = driver.find_element_by_xpath('//*[@id="loginbox"]/table/tbody/tr[2]/td[2]/input')
login.clear()
login.send_keys('2017kucpxxxx')

wait.until(lambda driver: driver.find_element_by_xpath('//*[@id="loginbox"]/table/tbody/tr[3]/td[2]/input'))
pwd = driver.find_element_by_xpath('//*[@id="loginbox"]/table/tbody/tr[3]/td[2]/input')
pwd.send_keys('xxpasswordxx')

loginElem = driver.find_element_by_xpath('//*[@id="loginbox"]/table/tbody/tr[5]/td/center/input')
loginElem.click()
driver.quit()
# webdriver.quit()
print('Login Successful!')

