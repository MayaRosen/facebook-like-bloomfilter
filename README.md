# Bloom Filter Service – Facebook-Like Platform

This repository contains a standalone **C++ Bloom Filter server** that supports the broader Facebook-like platform by checking whether submitted URLs are potentially malicious.

It is designed to integrate with the main application stack (Web, Android, and Server) to prevent unsafe content from being processed.

In addition to this floomfilter, there are separate repositories in this GitHub for:

  * [The Web Application](https://github.com/MayaRosen/facebook-like-web)
  * [The Android Application](https://github.com/MayaRosen/facebook-like-android)
  * [The Server Service](https://github.com/MayaRosen/facebook-like-server)

---

## Features

- ✅ Custom Bloom Filter implementation with bit array and multiple hash functions
- ✅ TCP server with support for adding/searching URLs
- ✅ Multithreaded client handling
- ✅ Integration with backend server for real-time filtering
- ✅ fast lookups

---

## Part of a Multi-Component System

This Bloom Filter service is one component of a full-stack social media platform:

- **🌐 Web Application:**  
  A React-based frontend that delivers an intuitive UI and allows seamless interaction with the platform.  
  [`facebook-like-web`](https://github.com/MayaRosen/facebook-like-web)

- **📱 Android Application:**  
  A mobile app providing similar functionality for Android users.  
  [`facebook-like-android`](https://github.com/MayaRosen/facebook-like-android)

- **🧠 Backend Server:**  
  A Node.js/Express server that handles business logic, authentication, and data persistence. It integrates with this Bloom Filter service for URL filtering.  
  [`facebook-like-server`](https://github.com/MayaRosen/facebook-like-server)

---

## How It Works

The Bloom Filter server listens on a TCP port (default: `5555`) and accepts two types of client requests:

- `1\n<url>` – Add a URL to the Bloom Filter.
- `2\n<url>` – Search if a URL is (likely) already present.

The Bloom Filter uses one or two hash functions (`Hash1`, `Hash2`) and maps hashed values into a fixed-size boolean array.

The `facebook-like-server` project connects via TCP and sends requests using a simple protocol via the `tcpClient.js` module.

---

## **Enjoy!**
